#ifndef BLD_EXT_MEMORY_H
#define BLD_EXT_MEMORY_H

#include "Common/LibDef.h"
#include "BLD_Ext_Memory_Cfg.h"

#ifndef BLD_EXT_MEM_TRIG_ADDR
#define BLD_EXT_MEM_TRIG_ADDR   0
#define BLD_EXT_MEM_TRIG_LEN    1
#endif

#ifndef BLD_EXT_MEM_HEX_ADDR
#define BLD_EXT_MEM_HEX_ADDR    (BLD_EXT_MEM_TRIG_ADDR+BLD_EXT_MEM_TRIG_LEN)
#endif

public void BLD_Ext_Memory_Init(void);

#define BLD_FW_NEW_UPDATE   1
#define BLD_FW_UP_TO_DATE   0
public bool BLD_Ext_Memory_GetTriggerState(void);
public void BLD_Ext_Memory_WriteTriggerState(bool State);
    
public uint8_t BLD_Ext_Memory_ReadHex(void);
public void BLD_Ext_Memory_Download_Tasks(void);

#endif