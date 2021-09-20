#ifndef BOOTLOADER_H
#define	BOOTLOADER_H

#include "Common/LibDef.h"
#include "Bootloader_Cfg.h"

#ifndef BLD_BUFFER_SIZE
#define BLD_BUFFER_SIZE         48
#endif

public void BootLoader_Initialize(void);
public void BootLoader_Deinitialize(void);
public void BootLoader_Tasks(void);

#endif