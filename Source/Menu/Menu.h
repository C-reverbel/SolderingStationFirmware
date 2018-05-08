//
// Created by carlos on 07/05/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_SCREEN_H
#define SOLDERINGSTATIONFIRMWARE_SCREEN_H

#include "../LCD/LCD.h"


class Menu {

protected:
    static const char leftArrow = '<';
    static const char rightArrow = '>';
    static const char degree = '\337';
    static LiquidCrystal* _lcd;

public:
    Menu();
    static void attachLCD(LiquidCrystal* lcd);
    void refreshScreen();
    void update();


};


#endif //SOLDERINGSTATIONFIRMWARE_SCREEN_H
