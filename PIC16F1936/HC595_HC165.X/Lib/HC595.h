#ifndef HC595_H
#define HC595_H

#include "LibDef.h"
#include "project_cfg.h"

public void HC595_Init(void);
public void HC595_Write(uint8_t Idx, uint8_t Value);
/* ************************************************************************** */
void HC595_Spi_Open(void);
void HC595_Spi_Close(void);
void HC595_Spi_Write(uint8_t b);
void HC595_NMR_SetState(bool x);
void HC595_NOE_SetState(bool x);
void HC595_NCS_SetState(bool x);

#endif
