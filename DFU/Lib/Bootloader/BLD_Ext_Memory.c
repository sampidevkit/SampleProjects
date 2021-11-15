#include "libcomp.h"
#include "BLD_Ext_Memory.h"

private uint32_t HexDataAddr;

public void BLD_Ext_Memory_Init(void)
{
    BLD_Ext_Memory_Driver_Init();
    HexDataAddr=BLD_EXT_MEM_HEX_ADDR;
}

public bool BLD_Ext_Memory_GetTriggerState(void)
{
    if(BLD_Ext_Memory_ReadByte(BLD_EXT_MEM_TRIG_ADDR)==0b10101010)
        return BLD_FW_NEW_UPDATE;

    return BLD_FW_UP_TO_DATE;
}

public void BLD_Ext_Memory_WriteTriggerState(bool State)
{
    if(State==BLD_FW_NEW_UPDATE)
        BLD_Ext_Memory_Full_Erase();
    else
    {
        BLD_Ext_Memory_Block_Erase(BLD_EXT_MEM_TRIG_ADDR);
        BLD_Ext_Memory_WriteByte(BLD_EXT_MEM_TRIG_ADDR, 0x00);
    }
}

public uint8_t BLD_Ext_Memory_ReadHex(void)
{
    return BLD_Ext_Memory_ReadByte(HexDataAddr++);
}

private bool Is_last_line(uint8_t c)
{
    static const uint8_t last_line[]=":00000001FF";
    static uint8_t matched=0;

    if(c==last_line[matched])
    {
        matched++;

        if(matched==11)
        {
            matched=0;
            return 1;
        }
    }
    else
        matched=0;

    return 0;
}

public void BLD_Ext_Memory_Download_Tasks(void) // <editor-fold defaultstate="collapsed" desc="Download task">
{
    static bool new_download=1;

    while(BLD_Downloader_IsRxReady())
    {
        uint8_t c=BLD_Downloader_Read();

        if(c=='\n')
        {
            while(!BLD_Downloader_IsTxReady());

            BLD_Downloader_Write('A');
        }
        else
        {
            if(new_download==1)
            {
                new_download=0;
                BLD_Ext_Memory_Full_Erase();
            }

            BLD_Ext_Memory_WriteByte(HexDataAddr++, c);

            if(Is_last_line(c))
            {
                BLD_Ext_Memory_WriteByte(BLD_EXT_MEM_TRIG_ADDR, 0b10101010); // new FW trigger code
                BLD_Downloader_Write('A');
                new_download=1;
            }
        }
    }
} // </editor-fold>
