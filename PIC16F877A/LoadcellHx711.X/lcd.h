#ifndef _LCD_XC_H
#define	_LCD_XC_H

#include <stdint.h>

// set up the timing for the LCD delays
#define LCD_delay           5     // ~5mS
#define LCD_Startup         15    // ~15mS
#define _XTAL_FREQ          20000000

// Command set for Hitachi 44780U LCD display controller
// Command set for Hitachi 44780U LCD display controller
#define LCD_CLEAR 0x01    // It clears everythings 
#define LCD_HOME 0x02   // set the cursor to first line and first row
#define LCD_CURSOR_BACK 0x10 // moves curson one position back
#define LCD_CURSOR_FWD 0x14  //moves curson one position forward
#define LCD_PAN_LEFT 0x18       // used to scroll text left side to scroll text
#define LCD_PAN_RIGHT 0x1C   // used to scroll text right side to scroll text
#define LCD_CURSOR_OFF 0x0C // stops display curson on screen
#define LCD_CURSOR_ON 0x0E  // turns on cursor display
#define LCD_CURSOR_BLINK 0x0F  // curson keeps blinking
#define LCD_CURSOR_LINE2 0xC0   // move curson to scond line or second row

// display controller setup commands from page 46 of Hitachi datasheet
#define FUNCTION_SET 0x28 // 4 bit interface, 2 lines, 5x8 font
#define ENTRY_MODE 0x06 // increment mode
#define DISPLAY_SETUP 0x0C // display on, cursor off, blink offd


//----------------------------------------------------------------------
// Definitions specific to the PICDEM 2 Plus
// These apply to the Black (2011) version.
//----------------------------------------------------------------------

// single bit for selecting command register or data register
#define instr        0
#define data         1

// These #defines create the pin connections to the LCD in case they are changed on a future demo board
#define LCD_PORT PORTD
#define LCD_PWR PORTDbits.RD7 // LCD power pin
#define LCD_EN PORTDbits.RD6 // LCD enable
#define LCD_RW PORTDbits.RD5 // LCD read/write line
#define LCD_RS PORTDbits.RD4 // LCD register select line

#define NB_LINES    2                                   // Number of display lines
#define NB_COL      16                                  // Number of characters per line

// Function prototypes
/**
  @Summary
    initialize the LCD module

  @Description
    This routine initializes the LCD driver.
    This routine must be called before any other LCD routine is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
 */
void LCD_Initialize(void);

/**
 @Summary
   Writes character to LCD at current cursor position

 @Description
   This function displays the specified ASCII character at current position on the LCD

 @Preconditions
   None

 @Param
   ASCII character to be displayed

 @Returns
   None
 */
void LCDPutChar(uint8_t ch);

/**
  @Summary
    send an ASCII command to the LCD in instruction mode

  @Description
    This routine writes character to LCD command register

  @Preconditions
    None

  @Param
    ASCII command 

  @Returns
    None
 */
void LCDPutCmd(uint8_t ch);

/**
  @Summary
    display a string

  @Description
    This routine writes string to LCD at current cursor position

  @Preconditions
    None

  @Param
    Pointer to string

  @Returns
    None
 */
void LCDPutStr(const uint8_t *);

/**
  @Summary
    Fuction to write a nibble

  @Description
    This function writes the specified nibble to the LCD.

  @Preconditions
    None

  @Param
    data byte to be written to display

  @Returns
    None
 */
void LCDWriteNibble(uint8_t ch, uint8_t rs);

/**
  @Summary
    Initialization routine that takes inputs from the EUSART GUI.

  @Description
    This function positions the cursor at the specified Line and column.

  @Preconditions
    None

  @Param
    Column and line at which the cursor should be positioned at

  @Returns
    None

  @Comment
      0 <= pos <= 15
      0 <= ln <= 1
 */
//void LCDGoto(uint8_t ln, uint8_t pos);
//void LCDvt(unsigned uint8_t line, unsigned uint8_t column);
void LCD_clear(void);
void LCDGoto(uint8_t line, uint8_t column);

#endif	/* _LCD_XC_H */