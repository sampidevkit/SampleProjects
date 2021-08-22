
/* 
 * File:   LCD.h
 * Author: SANG
 *
 * Created on June 27, 2021, 8:27 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef LCD4BIT_H
#define	LCD4BIT_H

#include "system.h"
#include "config.h"




// misc display defines-
#define LCD_LINE_1  0x80
#define LCD_LINE_2  0xC0
#define LCD_CLEAR   0x01

// prototype statements
void LCD_PulseEnable (void);
void LCD_SetData(unsigned char data);


void LCD_Init(void);
void LCD_WriteCommand (unsigned char cmd);
void LCD_Goto(unsigned char line, unsigned char pos);
void LCD_Clear(void);
void LCD_WriteChar (char c);
void LCD_WriteString (char *str);
void LCD_WriteSigned(int32_t number);
void LCD_WriteUnSigned(uint32_t number);
void LCD_WriteFloat(float f);
void LCD_WriteBinany(int8_t b);

#endif


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

