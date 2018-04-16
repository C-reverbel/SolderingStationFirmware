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
#include "GPIO/FastGPIO.h"

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

template<typename Pin>
class LiquidCrystal {
    public:
        LiquidCrystal(Pin& rs_pin, Pin& rw_pin) : _rs_pin(rs_pin), _rw_pin(rw_pin) {
            _rs_pin.setOutputHigh();
        }

        //void write(const char* data, size_t length) {
            //pin = 1;
            //pin = 0;
        //}
    private:
        Pin& _rs_pin; // LOW: command.  HIGH: character.
        Pin& _rw_pin; // LOW: write to LCD.  HIGH: read from LCD.
        //Pin& _enable_pin; // activated by a HIGH pulse.
        //Pin& _data_pins[8];
};




#endif //SOLDERINGSTATIONFIRMWARE_LCD_H
