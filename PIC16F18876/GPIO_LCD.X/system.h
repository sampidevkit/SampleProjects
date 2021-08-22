/* 
 * File:   system.h
 * Author: SANG
 *
 * Created on July 15, 2021, 9:57 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "stdio.h"
#include "string.h" 
    
#define _XTAL_FREQ 32000000

#define LCD_RS LATCbits.LATC0 
#define LCD_EN LATCbits.LATC1 
#define LCD_C4 LATCbits.LATC4 
#define LCD_C5 LATCbits.LATC5
#define LCD_C6 LATCbits.LATC6
#define LCD_C7 LATCbits.LATC7   

#define NUT_NHAN PORTDbits.RD0 
    
void delay_ms(uint16_t time);    

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

