#ifndef SOLDERINGSTATIONFIRMWARE_SCREEN_H
#define SOLDERINGSTATIONFIRMWARE_SCREEN_H

#include "frontend/USER_IO/Button.h"
#include "utils/LCD/LCD.h"


class Menu {
protected:
    static const char degree_symbol = '\337';
    static const char leftArrow = '<';
    static const char rightArrow = '>';

    static String opts_menu_selection;
    static String app_menu_selection;
    static String cal_menu_selection;
    static String menu_text;

    static LiquidCrystal* _lcd;
public:
    enum MenuScreen{
        SELECTION_MENU,
        APP_MENU,
        OPTIONS_MENU
    };
    struct userIO{
        bool btn1;
        bool btn2;
        int rotIncr;
    };
    MenuScreen screen;

public:
    Menu(){};

    static void attachLCD(LiquidCrystal* lcd);
    static String getMenuString(Menu::MenuScreen screen);



};

#endif //SOLDERINGSTATIONFIRMWARE_SCREEN_H