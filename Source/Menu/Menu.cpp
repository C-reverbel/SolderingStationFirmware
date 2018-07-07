#include "Menu.h"

// reserve memory to the static variable to avoid linker errors
LiquidCrystal *Menu::_lcd;
bool* Menu::_btn1;
bool* Menu::_btn2;

Menu::Menu(){
}

void Menu::attachLCD(LiquidCrystal* lcd){
    _lcd = lcd;
    _lcd->begin(8,2);
    _lcd->clear();
    _lcd->setCursor(0,0);
}

void Menu::attachButtonsValues(bool* btn1, bool* btn2){
    _btn1 = btn1;
    _btn2 = btn2;
}