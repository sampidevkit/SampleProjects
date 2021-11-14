#ifndef BLD_EXT_MEMORY_CFG_H
#define BLD_EXT_MEMORY_CFG_H

#define BLD_Downloader_IsRxReady()              UART2_IsRxReady()
#define BLD_Downloader_IsTxReady()              UART2_IsTxReady()
#define BLD_Downloader_IsTxDone()               UART2_IsTxDone()
#define BLD_Downloader_Write(byte)              UART2_Write(byte)
#define BLD_Downloader_Read()                   UART2_Read()

#define BLD_EXT_MEM_BLOCK_SIZE                  SST25_SECTOR_LENGTH
#define BLD_EXT_MEM_TRIG_ADDR                   0

#define BLD_Ext_Memory_Driver_Init()            SST25_Init()
#define BLD_Ext_Memory_Erase()                  SST25_Chip_Erase()
#define BLD_Ext_Memory_ReadByte(addr)           SST25_ReadByte(addr)
#define BLD_Ext_Memory_WriteByte(addr, data)    SST25_WriteByte(addr, data)

#endif