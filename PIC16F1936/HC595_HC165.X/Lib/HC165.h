#ifndef HC165_H
#define	HC165_H

#include "LibDef.h"
#include "project_cfg.h"

public void HC165_Init(void);
public uint8_t HC165_Read(uint8_t Idx);
/* ************************************************************************** */
void HC165_Spi_Open(void);
void HC165_Spi_Close(void);
uint8_t HC165_Spi_Read(void);
void HC165_NCS_SetState(bool x);
void HC165_NLD_SetState(bool x);

#endif
