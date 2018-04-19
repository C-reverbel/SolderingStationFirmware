//
// Created by carlos on 16/04/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_LCD_H
#define SOLDERINGSTATIONFIRMWARE_LCD_H

//
// Created by carlos on 15/04/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "Print.h"
#include "../GPIO/GPIO.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00


class LiquidCrystal : public Print {

public:

    class PinCollection {
        Pin _pins[8];
        size_t _size;

    public:
        PinCollection(Pin pin1 = Pin(21), Pin pin2 = Pin(21),
                      Pin pin3 = Pin(21), Pin pin4 = Pin(21),
                      Pin pin5 = Pin(21), Pin pin6 = Pin(21),
                      Pin pin7 = Pin(21), Pin pin8 = Pin(21))
                : _pins({
                               pin1, pin2, pin3, pin4,
                               pin5, pin6, pin7, pin8
                       }) {
            _size = 0;
            for(Pin pin : _pins) {
                if(!pin.isValidPin()) break;
                ++_size;
            }
        }

        PinCollection(const PinCollection& other) : PinCollection() {
            *this = other;
        }

        PinCollection& operator=(const PinCollection& other) {
            _size = other._size;
            for(int i = 0; i< _size; i++) {
                _pins[i] = other._pins[i];
            }
            return *this;
        }
        // O ERRO ESTA AQUI
        PinCollection& operator=(uint8_t value) {
            for (int i = 0; i < _size; i++) {
                _pins[i] = (value >> i) & 0x01;
            }
            return *this;
        }

    };

    enum class Mode {
        fourBit,
        eightBit
    };

    LiquidCrystal(Pin rs, Pin enable, Pin d0, Pin d1, Pin d2, Pin d3, Pin d4, Pin d5, Pin d6, Pin d7)
            : LiquidCrystal(Mode::eightBit, rs, Pin(21), enable, d0, d1, d2, d3, d4, d5, d6, d7) {}
    LiquidCrystal(Pin rs, Pin rw, Pin enable, Pin d0, Pin d1, Pin d2, Pin d3, Pin d4, Pin d5, Pin d6, Pin d7)
            : LiquidCrystal(Mode::eightBit, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}
    LiquidCrystal(Pin rs, Pin rw, Pin enable, Pin d0, Pin d1, Pin d2, Pin d3)
            : LiquidCrystal(Mode::fourBit, rs, rw, enable, d0, d1, d2, d3, Pin(21), Pin(21), Pin(21), Pin(21)) {}
    LiquidCrystal(Pin rs, Pin enable, Pin d0, Pin d1, Pin d2, Pin d3)
            : LiquidCrystal(Mode::fourBit, rs, Pin(21), enable, d0, d1, d2, d3, Pin(21), Pin(21), Pin(21), Pin(21)) {}

    void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

    void clear();
    void home();

    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();

    void createChar(uint8_t, uint8_t[]);
    void setCursor(uint8_t, uint8_t);
    virtual size_t write(uint8_t);
    void command(uint8_t);

    using Print::write;
private:
    LiquidCrystal(Mode mode, Pin rs, Pin rw, Pin enable,
                  Pin d0, Pin d1, Pin d2, Pin d3,
                  Pin d4, Pin d5, Pin d6, Pin d7);

    void send(uint8_t, bool);
    void write4bits(uint8_t);
    void write8bits(uint8_t);
    void pulseEnable();
public:

    Mode _mode;
    Pin _rs; // LOW: command.  HIGH: character.
    Pin _rw; // LOW: write to LCD.  HIGH: read from LCD.
    Pin _en; // activated by a HIGH pulse.

    PinCollection _pins; // data pins vector


    uint8_t _displayfunction;
    uint8_t _displaycontrol;
    uint8_t _displaymode;

    uint8_t _initialized;

    uint8_t _numlines,_currline;



};




#endif //SOLDERINGSTATIONFIRMWARE_LCD_H
