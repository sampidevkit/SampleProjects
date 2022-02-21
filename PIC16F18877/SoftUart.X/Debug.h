#ifndef DEBUG_H
#define DEBUG_H

#include "Debug_Cfg.h"

void Debug_Init(void);
void Debug_Putc(char);
void Debug_Puts(const char *);

#ifdef USE_STDIO
#include <stdio.h>

#define __db(...)   printf(__VA_ARGS__)
#else
#define __db(s)     Debug_Puts(s) 
#endif
#endif