#ifndef BLD_EXT_MEMORY_H
#define BLD_EXT_MEMORY_H

#include "Common/LibDef.h"
#include "BLD_Ext_Memory_Cfg.h"

/* ******************************************************** External Memory Maps
 * [      Offset        ][    Length    ][        Parameters      ]
 * [Address + 0         ][      1       ][Bootloader trigger state]
 * [Address + 1         ][      2       ][Number of hex lines     ]
 * [Address + 3         ][      2       ][Hex file checksum       ]
 * [Address + 5         ][Block size - 5][Reserved                ]
 * [Address + Block size][      n       ][Hex files data          ]
 * ************************************************************************** */

#ifndef BLD_EXT_MEM_BLOCK_SIZE
#define BLD_EXT_MEM_BLOCK_SIZE       4096
#endif

#ifndef BLD_EXT_MEM_TRIG_ADDR
#define BLD_EXT_MEM_TRIG_ADDR       0
#endif

#define BLD_EXT_MEM_TRIG_LEN        1

#define BLD_EXT_MEM_HEXLINE_ADDR    (BLD_EXT_MEM_TRIG_ADDR+BLD_EXT_MEM_TRIG_LEN)
#define BLD_EXT_MEM_HEXLINE_LEN     2

#define BLD_EXT_MEM_CHECKSUM_ADDR   (BLD_EXT_MEM_HEXLINE_ADDR+BLD_EXT_MEM_HEXLINE_LEN)
#define BLD_EXT_MEM_CHECKSUM_LEN    2

#define BLD_EXT_MEM_HEX_ADDR        (BLD_EXT_MEM_TRIG_ADDR+BLD_EXT_MEM_BLOCK_SIZE)

public void BLD_Ext_Memory_Init(void);

#define BLD_FW_NEW_UPDATE           1
#define BLD_FW_UP_TO_DATE           0
public bool BLD_Ext_Memory_GetTriggerState(void);
public void BLD_Ext_Memory_WriteTriggerState(bool State);
    
public uint8_t BLD_Ext_Memory_ReadHex(void);
public void BLD_Ext_Memory_Download_Tasks(void);

#endif