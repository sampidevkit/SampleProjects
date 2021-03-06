/////////////////////////////////////////////////////////////////////////
////                                                                 ////
////  FAT file system library (FAT16 & FAT32) for CCS PIC C compiler ////
////                                                                 ////
////  This library is for reading files only.                        ////
////  Long file name (LFN) is not supported (maximum file name is 12 ////
////  character)                                                     ////
////                    ----- User Functions -----                   ////
////                                                                 ////
////  sdcard_init();                                                 ////
////   Initializes the media. Returns 0 if OK, non-zero if error.    ////
////   Must be called before any other function.                     ////
////                                                                 ////
////  sdcard_read_byte(int32 addr, int8* data);                      ////
////   Reads a byte from the MMC/SD card at address 'addr', saves to ////
////   pointer 'data'. Returns 0 if OK, non-zero if error.           ////
////                                                                 ////
////  fat_init();                                                    ////
////   Initializes the FAT library. Returns 0 if OK, 1 if error.     ////
////                                                                 ////
////  fat_open_file(int8* fname);                                    ////
////   Opens file stream. fname is file name. Returns 0 if OK and 1  ////
////   if the opening process faced problem (file not found, long    ////
////   file name ...........).                                       ////
////                                                                 ////
////  fat_read_data(int32 size, int8* data);                         ////
////   Reads an array (data) of size 'size' from the opened file.    ////
////   Returns 0 if OK, 1 if error or end of file is reached.        ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////
////                                                                 ////
////  http://ccspicc.blogspot.com/                                   ////
////  electronnote@gmail.com                                         ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////


#include <string.h>
#ignore_warnings    240
// SD card definitions
static int16 timeout;

enum _card_type
{
    MMC,
    SDSC,
    SDHC
} g_card_type;

typedef enum _sdcard_err
{
    sdcard_goodec=0,
    sdcard_idle=0x01,
    sdcard_timeout=0x80,
    sdcard_illegal_cmd=0x04
} sdcard_err;

#define GO_IDLE_STATE 0
#define SEND_IF_COND 8
#define SET_BLOCKLEN 16
#define SEND_APP_OP_COND 41
#define APP_CMD 55
#define READ_OCR 58

void send_sdcard_command(int8 command, int32 sd_data, int8 sd_crc);
sdcard_err sdcard_init(void);
int1 sdcard_read_byte(int32 addr, int8* data);
sdcard_err sdcard_get_r1(void);
sdcard_err sdcard_get_r7(void);
sdcard_err sdcard_go_idle_state(void);
sdcard_err sdcard_send_if_cond(void);
sdcard_err sdcard_send_app_cmd(void);
sdcard_err sdcard_sd_send_op_cond(void);
sdcard_err sdcard_read_ocr(int8* _ocr_byte_3);
sdcard_err sdcard_set_blocklen(void);
int1 sdcard_stop_transmission(void);
void sdcard_select(void);
void sdcard_deselect(void);

// FAT System definitions
static int1 read_in_progress=0, fat_type=0;
static int8 Sectors_Per_Cluster;
static int16 Bytes_Per_Cluster;
static int32 fat_Start, fat_Length, Root_Dir, Data_Start, address_pointer, file_pointer,
        file_size=0, file_start_cluster, file_sector_number;

int1 fat_init(void);
int1 fat_open_file(int8* fname);
int1 fat_read_data(int32 size, int8* data);
int1 get_file_name(int32 file_entry_addr, int8 sname[]);
int32 get_next_cluster(int32 my_cluster);
int8 sdcard_wait_for_token(void);

// SD Card functions

sdcard_err sdcard_init(void) // <editor-fold defaultstate="collapsed" desc="SD card init">
{
    int8 i, resp, ocr_byte_3;
#if defined(SDCARD_SPI_HW)
    setup_spi(SPI_MASTER|SPI_H_TO_L|SPI_CLK_DIV_64|SPI_XMIT_L_TO_H);
#define sdcard_xfer(x)    spi_read(x)
#else
#if defined(SDCARD_PIN_SCL)
    output_drive(SDCARD_PIN_SCL);
#endif
#if defined(SDCARD_PIN_SDO)
    output_drive(SDCARD_PIN_SDO);
#endif
#if defined(SDCARD_PIN_SDI)
    output_float(SDCARD_PIN_SDI);
#endif
#use spi(MASTER, DI=SDCARD_PIN_SDI, DO=SDCARD_PIN_SDO, CLK=SDCARD_PIN_SCL, BITS=8, MSB_FIRST, MODE=3, baud=400000)
#define sdcard_xfer(x)    spi_xfer(x)
#endif

    output_high(SDCARD_PIN_SELECT);
    output_drive(SDCARD_PIN_SELECT);
    delay_ms(250);

    for(i=0; i<10; i++) // Send 80 cycles
        sdcard_xfer(0xFF);

    i=0;

    while((resp!=sdcard_idle) && (i<5))
    {
        i++;
        sdcard_select();
        resp=sdcard_go_idle_state(); // Send CMD0
        sdcard_deselect();
    }

    if(resp!=sdcard_idle)
        return resp;

    sdcard_select();
    resp=sdcard_send_if_cond(); // Send CMD8
    sdcard_deselect();

    if(resp!=sdcard_idle)
        return resp;

    i=0;

    do
    {
        sdcard_select();
        resp=sdcard_send_app_cmd(); // Send CMD58

        if((resp!=sdcard_idle) && (resp!=sdcard_illegal_cmd) && (resp!=0))
        {
            sdcard_deselect();
            return resp;
        }

        resp=sdcard_sd_send_op_cond(); // Send ACMD41
        sdcard_deselect();
        delay_ms(100);
        i++;
    }
    while((resp==0x01) && (i<254));

    sdcard_deselect();

    if((resp!=0||i>=254) && (resp!=sdcard_illegal_cmd))
        return sdcard_timeout;

    if(resp==0x04)
        g_card_type=MMC; // MMC type
    else
        g_card_type=SDSC; // SDSC or SDHC type

    if(g_card_type==SDSC)
    {
        sdcard_select();
        resp=sdcard_read_ocr(&ocr_byte_3);
        sdcard_deselect();

        if(resp!=sdcard_idle&&resp!=sdcard_illegal_cmd)
            return resp;

        if(resp!=sdcard_illegal_cmd)
        {
            if(bit_test(ocr_byte_3, 6)) // If bit 30 of the OCR register is 1 (CCS is 1) ==> SDHC type
                g_card_type=SDHC;
        }
    }

    sdcard_select();
    resp=sdcard_set_blocklen();
    sdcard_deselect();

    if(resp!=0)
        return sdcard_timeout;

#if defined(SDCARD_SPI_HW)
    // Speed up the SPI bus
    setup_spi(SPI_MASTER|SPI_H_TO_L|SPI_CLK_DIV_4|SPI_XMIT_L_TO_H);
#else
#use spi(MASTER, DI=SDCARD_PIN_SDI, DO=SDCARD_PIN_SDO, CLK=SDCARD_PIN_SCL, BITS=8, MSB_FIRST, MODE=3)
#endif

    return sdcard_goodec;
} // </editor-fold>

int1 sdcard_read_byte(int32 addr, int8* data) // <editor-fold defaultstate="collapsed" desc="SD card reads byte">
{
    int16 i, byte_addr;
    int32 sector_number;

    sector_number=addr/512;

    if(g_card_type!=SDHC)
        sector_number=sector_number<<9;

    byte_addr=addr%512;
    sdcard_select();
    send_sdcard_command(17, sector_number, 0xFF);

    if(sdcard_wait_for_token()==0xFE)
    {
        for(i=0; i<byte_addr; i++)
            sdcard_xfer(0xFF);

        *data=sdcard_xfer(0xFF);
        byte_addr++;

        for(i=byte_addr; i<512; i++)
            sdcard_xfer(0xFF);

        for(i=0; i<2; i++)
            sdcard_xfer(0xFF);

        sdcard_deselect();

        return sdcard_goodec;
    }

    sdcard_deselect();
    return 1;
} // </editor-fold>

void send_sdcard_command(int8 command, int32 sd_data, int8 sd_crc) // <editor-fold defaultstate="collapsed" desc="SD card command">
{
    int8 i;

    sdcard_xfer(0x40|command);

    for(i=0; i<4; i++)
        sdcard_xfer(sd_data>>(3-i) * 8);

    sdcard_xfer(sd_crc);
} // </editor-fold>

sdcard_err sdcard_go_idle_state(void) // <editor-fold defaultstate="collapsed" desc="SD card idle state">
{
    send_sdcard_command(GO_IDLE_STATE, 0, 0x95);
    return sdcard_get_r1();
} // </editor-fold>

sdcard_err sdcard_send_if_cond(void) // <editor-fold defaultstate="collapsed" desc="SD card send IF cond">
{
    send_sdcard_command(SEND_IF_COND, 0x1AA, 0x87);
    return sdcard_get_r7();
} // </editor-fold>

sdcard_err sdcard_send_app_cmd(void) // <editor-fold defaultstate="collapsed" desc="SD card send APP cmd">
{
    send_sdcard_command(APP_CMD, 0, 0xFF);
    return sdcard_get_r1();
} // </editor-fold>

sdcard_err sdcard_sd_send_op_cond(void) // <editor-fold defaultstate="collapsed" desc="SD card send OP cond">
{
    send_sdcard_command(SEND_APP_OP_COND, 0x40000000, 0xFF);
    return sdcard_get_r1();
} // </editor-fold>

sdcard_err sdcard_read_ocr(int8* _ocr_byte_3) // <editor-fold defaultstate="collapsed" desc="comment">
{
    unsigned int8 i, response;
    timeout=0xFFFF;
    send_sdcard_command(READ_OCR, 0, 0xFF);
    while(timeout)
    {
        response=sdcard_xfer(0xFF);
        if(response!=0xFF)
        {
            if(response==0x04) return response;
            *_ocr_byte_3=sdcard_xfer(0xFF);
            for(i=0; i<3; i++)
                sdcard_xfer(0xFF);
            return sdcard_idle;
            timeout--;
        }
    }
    return sdcard_timeout;
} // </editor-fold>

sdcard_err sdcard_set_blocklen(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    send_sdcard_command(SET_BLOCKLEN, 512, 0xFF);
    return sdcard_get_r1();
} // </editor-fold>

sdcard_err sdcard_get_r1(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int8 response=0;

    timeout=0xFFFF;

    while(timeout)
    {
        response=sdcard_xfer(0xFF);

        if(response!=0xFF)
            return response;

        timeout--;
    }

    return sdcard_timeout;
} // </editor-fold>

sdcard_err sdcard_get_r7(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int8 i, response=0;

    timeout=0xFFFF;

    while(timeout)
    {
        response=sdcard_xfer(0xFF);

        if(response!=0xFF)
        {
            for(i=0; i<4; i++)
                sdcard_xfer(0xFF);

            return sdcard_idle;
        }

        timeout--;
    }

    return sdcard_timeout;
} // </editor-fold>

int1 sdcard_stop_transmission(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int8 resp=0xFF;

    timeout=0xFFFF;

    while((resp!=sdcard_idle) && (resp!=sdcard_illegal_cmd) && (resp!=0)&&timeout)
    {
        send_sdcard_command(12, 0, 0xFF); // Send stop transmission command
        resp=sdcard_get_r1();
        timeout--;
    }

    if(timeout)
        return 0;
    else
        return 1;
} // </editor-fold>

void sdcard_select(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    output_low(SDCARD_PIN_SELECT);
} // </editor-fold>

void sdcard_deselect(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    output_high(SDCARD_PIN_SELECT);
} // </editor-fold>

// FAT Functions

int1 fat_init(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int1 ec=0;
    int8 FATs;
    int16 Bytes_Per_Sector, Reserved_Sectors, Root_Entries, Small_Sectors;
    int32 Hidden_Sectors, Total_Sectors, Sectors_Per_FAT=0;

    ec|=sdcard_read_byte(0x0C, &Bytes_Per_Sector);
    Bytes_Per_Sector<<=8;
    ec|=sdcard_read_byte(0x0B, &Bytes_Per_Sector);
    ec|=sdcard_read_byte(0x0D, &Sectors_Per_Cluster);
    ec|=sdcard_read_byte(0x0F, &Reserved_Sectors);
    Reserved_Sectors<<=8;
    ec|=sdcard_read_byte(0x0E, &Reserved_Sectors);
    ec|=sdcard_read_byte(0x10, &FATs);
    ec|=sdcard_read_byte(0x14, &Small_Sectors);
    Small_Sectors<<=8;
    ec|=sdcard_read_byte(0x13, &Small_Sectors);
    ec|=sdcard_read_byte(0x1F, &Hidden_Sectors);
    Hidden_Sectors<<=8;
    ec|=sdcard_read_byte(0x1E, &Hidden_Sectors);
    Hidden_Sectors<<=8;
    ec|=sdcard_read_byte(0x1D, &Hidden_Sectors);
    Hidden_Sectors<<=8;
    ec|=sdcard_read_byte(0x1C, &Hidden_Sectors);
    ec|=sdcard_read_byte(0x23, &Total_Sectors);
    Total_Sectors<<=8;
    ec|=sdcard_read_byte(0x22, &Total_Sectors);
    Total_Sectors<<=8;
    ec|=sdcard_read_byte(0x21, &Total_Sectors);
    Total_Sectors<<=8;
    ec|=sdcard_read_byte(0x20, &Total_Sectors);

    if((Total_Sectors/Sectors_Per_Cluster)>65525)
        fat_type=1; // FAT32

    if(fat_type==0)
    { // If FAT16
        ec|=sdcard_read_byte(0x12, &Root_Entries);
        Root_Entries<<=8;
        ec|=sdcard_read_byte(0x11, &Root_Entries);
        ec|=sdcard_read_byte(0x17, &Sectors_Per_FAT);
        Sectors_Per_FAT<<=8;
        ec|=sdcard_read_byte(0x16, &Sectors_Per_FAT);
    }
    else
    { // If FAT32
        ec|=sdcard_read_byte(0x27, &Sectors_Per_FAT);
        Sectors_Per_FAT<<=8;
        ec|=sdcard_read_byte(0x26, &Sectors_Per_FAT);
        Sectors_Per_FAT<<=8;
        ec|=sdcard_read_byte(0x25, &Sectors_Per_FAT);
        Sectors_Per_FAT<<=8;
        ec|=sdcard_read_byte(0x24, &Sectors_Per_FAT);
    }

    if(ec!=0)
        return 1;

    Bytes_Per_Cluster=Sectors_Per_Cluster * Bytes_Per_Sector;
    fat_Length=Sectors_Per_FAT * Bytes_Per_Sector;
    fat_Start=(int32) Reserved_Sectors * Bytes_Per_Sector;
    Root_Dir=fat_Start+(FATs*fat_Length);

    if(fat_type==0)
    { // If FAT16
        Data_Start=(Root_Entries*0x20) + (Bytes_Per_Sector-1);
        Data_Start/=Bytes_Per_Sector;
        Data_Start+=Reserved_Sectors+(FATs*Sectors_Per_FAT);
        Data_Start*=Bytes_Per_Sector;
    }
    else // If FAT32
        Data_Start=Bytes_Per_Cluster+Root_Dir;

    return 0;
} // </editor-fold>

int1 fat_open_file(int8* fname) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int1 ok=0;
    int8 target_file[13], s_name[12], fname_parse_pos=0, name_size;
    int32 addr;

    while(fname[fname_parse_pos]!='\0'&&fname_parse_pos<13)
    {
        target_file[fname_parse_pos]=tolower(fname[fname_parse_pos]);
        fname_parse_pos++;
    }

    target_file[fname_parse_pos]='\0';
    name_size=strlen(target_file);

    if(name_size>12)
        return 1; // Return error (long file name is not supported)

    addr=Root_Dir;
    sdcard_select();

    if(sdcard_stop_transmission()!=0)
    {
        sdcard_deselect();
        return 1;
    }

    while(addr<Data_Start&&ok==0)
    {
        if(get_file_name(addr, s_name)!=0)
            return 1; // Error reading file name from the SD card or file not found

        if(strcmp(s_name, target_file)==0)
            ok=1;

        if(ok==0)
            addr+=32;
    }

    if(ok==0)
        return 1; // File not found ==> Error

    ok=0;
    ok|=sdcard_read_byte(addr+0x1F, &file_size);
    file_size<<=8;
    ok|=sdcard_read_byte(addr+0x1E, &file_size);
    file_size<<=8;
    ok|=sdcard_read_byte(addr+0x1D, &file_size);
    file_size<<=8;
    ok|=sdcard_read_byte(addr+0x1C, &file_size);
    ok|=sdcard_read_byte(addr+0x15, &file_start_cluster);
    file_start_cluster<<=8;
    ok|=sdcard_read_byte(addr+0x14, &file_start_cluster);
    file_start_cluster<<=8;
    ok|=sdcard_read_byte(addr+0x1B, &file_start_cluster);
    file_start_cluster<<=8;
    ok|=sdcard_read_byte(addr+0x1A, &file_start_cluster);

    if(fat_type==0)
        address_pointer=Data_Start+(file_start_cluster-2)*Bytes_Per_Cluster;
    else
        address_pointer=Root_Dir+(file_start_cluster-2)*Bytes_Per_Cluster;

    file_pointer=0;
    read_in_progress=0;
    file_sector_number=address_pointer/512;

    return ok;
} // </editor-fold>

int1 fat_read_data(int32 fsize, int8* fdata) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int8 j;
    int16 i;

    sdcard_select();

    if(file_pointer==file_size)
    {
        sdcard_stop_transmission();
        sdcard_deselect();
        return 1;
    }

    if(file_pointer+fsize>file_size)
    {
        fsize=file_size-file_pointer;
        fdata[fsize]='\0';
    }

    if(read_in_progress==1)
    {
        for(i=0; i<fsize; i++)
        {
            fdata[i]=sdcard_xfer(0xFF);
            file_pointer++;

            if((file_pointer%512)==0)
            {
                for(j=0; j<2; j++)
                    sdcard_xfer(0xFF);

#if defined (FILE_CLUSTER_CHECK)
                if((file_pointer%Bytes_Per_Cluster)==0)
                {
                    sdcard_stop_transmission();
                    file_start_cluster=get_next_cluster(file_start_cluster);

                    if(fat_type==0)
                        file_sector_number=(Data_Start+(file_start_cluster-2)*Bytes_Per_Cluster)/512;
                    else
                        file_sector_number=(Root_Dir+(file_start_cluster-2)*Bytes_Per_Cluster)/512;

                    if(g_card_type!=SDHC)
                        file_sector_number=file_sector_number<<9;

                    sdcard_select();
                    send_sdcard_command(18, file_sector_number, 0xFF); // Send multi-block read command
                }
#endif

                if(sdcard_wait_for_token()!=0xFE)
                {
                    sdcard_deselect();
                    return 1;
                }
            }
        }

        sdcard_deselect();
        return 0;
    }

    if(read_in_progress==0)
    {
        read_in_progress=1;

        if(g_card_type!=SDHC)
            file_sector_number=file_sector_number<<9;

        send_sdcard_command(18, file_sector_number, 0xFF); // Send multi-block read command

        if(sdcard_wait_for_token()==0xFE)
        {
            for(i=0; i<fsize; i++)
            {
                file_pointer++;
                fdata[i]=sdcard_xfer(0xFF);

                if((file_pointer%512)==0)
                {
                    for(j=0; j<2; j++)
                        sdcard_xfer(0xFF);

                    if(sdcard_wait_for_token()!=0xFE)
                    {
                        sdcard_deselect();
                        return 1;
                    }
                }
            }

            sdcard_deselect();
            return 0;
        }

        sdcard_deselect();
        return 1;
    }
} // </editor-fold>

int1 get_file_name(int32 file_entry_addr, int8 sname[]) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int8 buf, i, j=0;

    for(i=0; i<11; i++)
    {
        if(sdcard_read_byte(i+file_entry_addr, &buf)!=0)
            return 1;

        if((i==0) && (buf==0xE5))
            return 0; // Deleted file ==> Skip reading (go to next address)

        if((i==0) && (buf==0))
            return 1; // End of file names in the root directory

        if(buf!=' ')
        {
            sname[j]=tolower(buf);
            j+=1;
        }
    }

    sname[j]='\0';

    if(strlen(sname)>3)
    {
        j=strlen(sname);

        for(i=j; i>j-3; --i)
            sname[i]=sname[i-1];

        sname[i]='.';
    }

    sname[j+1]='\0';
    return 0;
} // </editor-fold>

#if defined (FILE_CLUSTER_CHECK)

int32 get_next_cluster(int32 my_cluster) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int32 next_cluster=0;

    if(fat_type==0)
    {
        sdcard_read_byte((my_cluster<<1)+FAT_Start+1, &next_cluster);
        next_cluster<<=8;
        sdcard_read_byte((my_cluster<<1)+FAT_Start, &next_cluster);
    }
    else
    {
        sdcard_read_byte((my_cluster<<2)+FAT_Start+3, &next_cluster);
        next_cluster<<=8;
        sdcard_read_byte((my_cluster<<2)+FAT_Start+2, &next_cluster);
        next_cluster<<=8;
        sdcard_read_byte((my_cluster<<2)+FAT_Start+1, &next_cluster);
        next_cluster<<=8;
        sdcard_read_byte((my_cluster<<2)+FAT_Start, &next_cluster);
    }

    return next_cluster;
} // </editor-fold>
#endif

int8 sdcard_wait_for_token(void) // <editor-fold defaultstate="collapsed" desc="comment">
{
    int8 response=0xFF;

    timeout=0xFFFF;

    while(timeout&&(response!=0xFE))
    {
        response=sdcard_xfer(0xFF);
        timeout--;
    }

    return response;
} // </editor-fold>
