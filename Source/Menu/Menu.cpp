#include "Menu.h"

// reserve memory to the static variable to avoid linker errors
LiquidCrystal *Menu::_lcd;

String Menu::app_menu_selection = "MAIN";
String Menu::cal_menu_selection  = "CAL ";
String Menu::opts_menu_selection = "OPTS";
String Menu::menu_text = "MENU";

void Menu::attachLCD(LiquidCrystal* lcd){
    _lcd = lcd;
    _lcd->begin(8,2);
    _lcd->clear();
    _lcd->setCursor(0,0);
}

String Menu::getMenuString(Menu::MenuScreen screen){
    switch(screen){
        case Menu::MenuScreen::APP_MENU:
            return Menu::app_menu_selection;
        break;
        case Menu::MenuScreen::OPTIONS_MENU:
            return Menu::opts_menu_selection;
        break;
    }
    return "";
}