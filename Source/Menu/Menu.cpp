//
// Created by carlos on 07/05/2018.
//

#include "Menu.h"
// reserve memory to the static variable to avoid linker errors
LiquidCrystal *Menu::_lcd;

Menu::Menu(){
}

void Menu::attachLCD(LiquidCrystal* lcd){
    _lcd = lcd;
    _lcd->begin(8,2);
    _lcd->clear();
    _lcd->setCursor(0,0);
}