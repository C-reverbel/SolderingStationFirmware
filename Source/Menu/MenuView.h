#ifndef SOLDERINGSTATIONFIRMWARE_MENUVIEW_H
#define SOLDERINGSTATIONFIRMWARE_MENUVIEW_H

#include "Menu.h"
#include "ApplicationMenu.h"
#include "SelectionMenu.h"

#include "../utils/LCD/LCD.h"
#include "../frontend/USER_IO/Button.h"
#include "../frontend/USER_IO/RotaryEncoder.h"
#include "OptionsMenu.h"

class MenuView {
public:
    static Button* _btn1;
    static Button* _btn2;
    static RotaryEncoder* _rotaryEnc;

    ApplicationMenu appMenu;
    SelectionMenu selectMenu;
    OptionsMenu optionsMenu;
    // edit here to add new menu
    static const uint8_t numberOfSelectableMenus = 2;
    uint8_t highlightedMenuIndex = 0;
    Menu::MenuScreen listOfSelectableMenus[numberOfSelectableMenus] = {
        Menu::MenuScreen::APP_MENU,
        Menu::MenuScreen::OPTIONS_MENU
    };
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

    Menu::userIO getIOValues();
    void resetSelectionMenu();
private:
    static void attachLCD(LiquidCrystal* lcd);
    static void attachButtons(Button* btn1, Button* btn2);
    static void attachRotaryEncoder(RotaryEncoder* rotaryEnc);

};

#endif //SOLDERINGSTATIONFIRMWARE_MENUVIEW_H