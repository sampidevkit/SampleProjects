#ifndef TEXTLCD_H
#define TEXTLCD_H

#include <stdint.h>
#include <stdbool.h>

#define LCD_PUT_STRING  0

typedef enum {
    LCD0802 = 0,
    LCD0804,
    LCD1602,
    LCD1604,
    LCD2002,
    LCD2004
} textlcd_t;

void TextLCD_Init(textlcd_t TextLcdType);
void TextLCD_Clear(void);
void TextLCD_PutChar(char data);
void TextLCD_SetCursor(uint8_t line, uint8_t idx);
void TextLCD_ClearLine(uint8_t line);
void TextLCD_Puts(uint8_t line, uint8_t idx, const char *data, uint8_t length_or_type);

#endif