#ifndef SOLDERINGSTATIONFIRMWARE_MENUVIEW_H
#define SOLDERINGSTATIONFIRMWARE_MENUVIEW_H

#include "Menu.h"
#include "ApplicationMenu.h"
#include "SelectionMenu.h"

#include "../LCD/LCD.h"
#include "../USER_IO/Button.h"
#include "../USER_IO/RotaryEncoder.h"

class MenuView {
public:
    static LiquidCrystal* _lcd;
    static Button* _btn1;
    static Button* _btn2;
    static RotaryEncoder* _rotaryEnc;

    static uint16_t setTemp;
    static uint16_t mesTemp;

    static Menu::MenuScreen currentScreen;
    static Menu::MenuScreen lastScreen;

    static ApplicationMenu appMenu;
    static SelectionMenu selectMenu;
private:
    static bool btn1Val;
    static bool btn2Val;

public:
    MenuView(LiquidCrystal* lcd, Button* btn1, Button* btn2, RotaryEncoder* rotaryEnc);

    static bool getBtn1Val(){
        return btn1Val;
    }
    static void setBtn1Val(bool value){
        btn1Val = value;
    }
    static bool getBtn2Val(){
        return btn2Val;
    }
    static void setBtn2Val(bool value){
        btn2Val = value;
    }

    void refreshScreen();
    Menu::userIO getIOValues();
private:
    static void attachLCD(LiquidCrystal* lcd);
    static void attachButtons(Button* btn1, Button* btn2);
    static void attachRotaryEncoder(RotaryEncoder* rotaryEnc);

};


#endif //SOLDERINGSTATIONFIRMWARE_MENUVIEW_H
