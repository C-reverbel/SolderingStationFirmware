//
// Created by carlos on 16/04/2018.
//
#include "LCD.h"
#include <util/delay.h>

#define LOW 0
#define HIGH 1

LiquidCrystal::LiquidCrystal(Mode mode, Pin rs, Pin rw, Pin enable, Pin d0, Pin d1, Pin d2, Pin d3,
        Pin d4, Pin d5, Pin d6, Pin d7)
: _mode(mode), _rs(rs), _rw(rw), _en(enable), _pins(d0,d1,d2,d3,d4,d5,d6,d7) {

    _rs = LOW;
    _en = LOW;

    if(_mode==Mode::fourBit){
        _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
    }
    else{
        _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS;
    }

};


void LiquidCrystal::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
    if (lines > 1) {
        _displayfunction |= LCD_2LINE;
    }
    _numlines = lines;
    _currline = 0;

    // for some 1 line displays you can select a 10 pixel high font
    if ((dotsize != 0) && (lines == 1)) {
        _displayfunction |= LCD_5x10DOTS;
    }

    // SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
    // according to datasheet, we need at least 40ms after power rises above 2.7V
    // before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
    _delay_us(50000);
    // Now we pull both RS and R/W low to begin commands
    _rs = LOW;
    _en = LOW;
    if (_rw.isValidPin()) {
        _rw = LOW;
    }

    //put the LCD into 4 bit or 8 bit mode
    if (! (_displayfunction & LCD_8BITMODE)) {
        // this is according to the hitachi HD44780 datasheet
        // figure 24, pg 46

        // we start in 8bit mode, try to set 4 bit mode
        write4bits(0x03);
        _delay_us(4500); // wait min 4.1ms

        // second try
        write4bits(0x03);
        _delay_us(4500); // wait min 4.1ms

        // third go!
        write4bits(0x03);
        _delay_us(150);

        // finally, set to 4-bit interface
        write4bits(0x02);
    } else {
        // this is according to the hitachi HD44780 datasheet
        // page 45 figure 23

        // Send function set command sequence
        command(LCD_FUNCTIONSET | _displayfunction);
        _delay_us(4500);  // wait more than 4.1ms

        // second try
        command(LCD_FUNCTIONSET | _displayfunction);
        _delay_us(150);

        // third go
        command(LCD_FUNCTIONSET | _displayfunction);
    }

    // finally, set # lines, font size, etc.
    command(LCD_FUNCTIONSET | _displayfunction);

    // turn the display on with no cursor or blinking default
    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    display();

    // clear it off
    clear();

    // Initialize to default text direction (for romance languages)
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    // set the entry mode
    command(LCD_ENTRYMODESET | _displaymode);

}

/* high level public functions - for the user! */
void LiquidCrystal::clear()
{
    command(LCD_CLEARDISPLAY);  // clear display, set cursor position to zero
    _delay_us(2000);  // this command takes a long time!
}

void LiquidCrystal::home()
{
    command(LCD_RETURNHOME);  // set cursor position to zero
    _delay_us(2000);  // this command takes a long time!
}

void LiquidCrystal::setCursor(uint8_t col, uint8_t row)
{
    int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
    if ( row >= _numlines ) {
        row = _numlines-1;    // we count rows starting w/0
    }

    command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void LiquidCrystal::noDisplay() {
    _displaycontrol &= ~LCD_DISPLAYON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::display() {
    _displaycontrol |= LCD_DISPLAYON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void LiquidCrystal::noCursor() {
    _displaycontrol &= ~LCD_CURSORON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::cursor() {
    _displaycontrol |= LCD_CURSORON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void LiquidCrystal::noBlink() {
    _displaycontrol &= ~LCD_BLINKON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::blink() {
    _displaycontrol |= LCD_BLINKON;
    command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void LiquidCrystal::scrollDisplayLeft(void) {
    command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void LiquidCrystal::scrollDisplayRight(void) {
    command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void LiquidCrystal::leftToRight(void) {
    _displaymode |= LCD_ENTRYLEFT;
    command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void LiquidCrystal::rightToLeft(void) {
    _displaymode &= ~LCD_ENTRYLEFT;
    command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void LiquidCrystal::autoscroll(void) {
    _displaymode |= LCD_ENTRYSHIFTINCREMENT;
    command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void LiquidCrystal::noAutoscroll(void) {
    _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
    command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
//void LiquidCrystal::createChar(uint8_t location, uint8_t charmap[]) {
//    location &= 0x7; // we only have 8 locations 0-7
//    command(LCD_SETCGRAMADDR | (location << 3));
//    for (int i=0; i<8; i++) {
//        write(charmap[i]);
//    }
//}

/* mid level public functions - for sending data/cmds */
inline void LiquidCrystal::command(uint8_t value) {
    send(value, LOW);
}
inline size_t LiquidCrystal::write(uint8_t value) {
    send(value, HIGH);
    return 1; // assume sucess
}

/* Low level private functions - data pushing commands */
void LiquidCrystal::send(uint8_t value, bool mode) {
    //_rs = mode;
    // if there is a RW pin indicated, set it low to Write
    if(_rw.isValidPin())
        //_rw = LOW;
    if (_displayfunction & LCD_8BITMODE){
        //write8bits(value);
    }
    else {
        //write4bits(value>>4);
        //write4bits(value);
    }
}
void LiquidCrystal::pulseEnable() {
    _en = LOW;
    _delay_us(1);
    _en = HIGH;
    _delay_us(1);   // enable pulse must be >450ns
    _en = LOW;
    _delay_us(100); // commands need > 37us to settle
}
void LiquidCrystal::write4bits(uint8_t value) {
    _pins = value;
    pulseEnable();
}
void LiquidCrystal::write8bits(uint8_t value) {
    _pins = value;
    pulseEnable();
}