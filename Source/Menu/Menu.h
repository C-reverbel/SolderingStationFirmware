//
// Created by carlos on 07/05/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_SCREEN_H
#define SOLDERINGSTATIONFIRMWARE_SCREEN_H

#include "USER_IO/Button.h"
#include "LCD/LCD.h"


class Menu {

protected:
    static const char leftArrow = '<';
    static const char rightArrow = '>';
    static const char degree_symbol = '\337';
    static LiquidCrystal* _lcd;
    static bool* _btn1;
    static bool* _btn2;

public:
    Menu();
    static void attachLCD(LiquidCrystal* lcd);
    static void attachButtonsValues(bool* btn1, bool* btn2);
    virtual void refreshScreen();
    virtual void updateFromBtns();


};


#endif //SOLDERINGSTATIONFIRMWARE_SCREEN_H