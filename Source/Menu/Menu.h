#ifndef SOLDERINGSTATIONFIRMWARE_SCREEN_H
#define SOLDERINGSTATIONFIRMWARE_SCREEN_H

#include "USER_IO/Button.h"
#include "LCD/LCD.h"


class Menu {

protected:
    static const char degree_symbol = '\337';
    static LiquidCrystal* _lcd;
    static bool* _btn1;
    static bool* _btn2;
    static bool* _locked_rotary_flag;
    static int* _rotaryIncr;
public:
    enum MenuScreen{
        SELECTION_MENU,
        APP_MENU
    };
    struct userIO{
        bool btn1;
        bool btn2;
        int rotIncr;
    };

public:
    Menu(){};

    static void attachLCD(LiquidCrystal* lcd);
    static void attachButtonsValues(bool* btn1, bool* btn2);
    static void attachLockedRotaryFlag(bool* locked_rotary_flag);
    static void attachRotaryEncoder(int* rotaryIncr);

    virtual void refreshScreen() = 0;
    virtual MenuScreen updateFromBtns() = 0;
public:
    MenuScreen screen;


};

#endif //SOLDERINGSTATIONFIRMWARE_SCREEN_H