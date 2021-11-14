#ifndef BLD_EXT_MEMORY_CFG_H
#define BLD_EXT_MEMORY_CFG_H

#define BLD_Downloader_IsRxReady()              0
#define BLD_Downloader_IsTxReady()              0
#define BLD_Downloader_IsTxDone()               0
#define BLD_Downloader_Write(byte)              
#define BLD_Downloader_Read()                   0x00

#define BLD_Ext_Memory_Driver_Init()            SST25_Init()
#define BLD_Ext_Memory_Erase()                  SST25_Chip_Erase()
#define BLD_Ext_Memory_ReadByte(addr)           SST25_ReadByte(addr)
#define BLD_Ext_Memory_WriteByte(addr, data)    SST25_WriteByte(addr, data)

#endif