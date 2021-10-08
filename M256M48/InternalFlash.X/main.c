#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart3.h"
#include "mcc_generated_files/memory/flash.h"

static const uint32_t __attribute((space(prog), aligned(FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS))) flash[FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS/4]={
    0x01020304, 0x05060708
};

static uint8_t data[FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS];

int main(void)
{
    uint32_t i, addr;
    uint8_t buffer[4];

    SYSTEM_Initialize();
    addr=(uint32_t) flash;
    printf("\nRuning");

    while(1)
    {
        if(UART3_IsRxReady())
        {
            switch(UART3_Read())
            {
                case 'r':
                case 'R':

                    printf("\nRead %08X: ", addr);

                    for(i=0; i<FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS; i+=4)
                    {
                        *((uint32_t *) buffer)=FLASH_ReadWord(addr+i);

                        if((buffer[0]!=data[i])||(buffer[1]!=data[i+1])||
                                (buffer[2]!=data[i+2])||(buffer[3]!=data[i+3]))
                        {
                            printf("\nRD %08X: ", addr+i);
                            printf("%02X%02X", buffer[0], buffer[1]);
                            printf("%02X%02X - ", buffer[2], buffer[3]);
                            printf("%02X%02X", data[i], data[i+1]);
                            printf("%02X%02X", data[i+2], data[i+3]);
                        }
                    }

                    printf("\nDone");
                    break;

                case 'w':
                case 'W':
                    for(i=0; i<FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS; i++)
                        data[i]=(uint8_t) rand();

                    FLASH_Unlock(FLASH_UNLOCK_KEY);

                    if(!FLASH_ErasePage(addr))
                    {
                        printf("\nErase error");
                        break;
                    }

                    for(i=0; i<FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS; i+=FLASH_WRITE_ROW_SIZE_IN_PC_UNITS)
                    {
                        if(!FLASH_WriteRow(addr+i, (uint32_t*) &data[i]))
                        {
                            printf("\nWrite error");
                            break;
                        }
                    }

                    FLASH_Lock();
                    printf("\nWrite done");
                    break;

                default:
                    break;
            }
        }
    }

    return 1;
}