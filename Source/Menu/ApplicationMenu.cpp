#include <string.h>
#include <util/delay.h>

#include "ApplicationMenu.h"

ApplicationMenu::ApplicationMenu() {
    this->screen = Menu::MenuScreen::APP_MENU;
}

// HIGH LEVEL FUNCTIONS
void ApplicationMenu::refreshScreen(uint16_t setTemp, uint16_t mesTemp, MenuModel::TempUnity tempUnity, bool isRotaryLocked) {
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); printSetTemp(setTemp,tempUnity);
    // print second line
    _lcd->setCursor(0,1); printMesTemp(mesTemp,tempUnity);
    //TODO change locked symbol
    if(isRotaryLocked){
        _lcd->setCursor(7,0); _lcd->print('&');
    }
}

// MID LEVEL FUNCTIONS
void ApplicationMenu::printSetTemp(uint16_t temperature, MenuModel::TempUnity unity) {
    _lcd->print("S:");_lcd->print(getTempString(temperature,unity));
}
void ApplicationMenu::printMesTemp(uint16_t temperature, MenuModel::TempUnity unity) {
    _lcd->print("M:");_lcd->print(getTempString(temperature,unity));
}
// LOW LEVEL FUNCTIONS
String ApplicationMenu::getTempString(uint16_t value, MenuModel::TempUnity unity) {
    String result = "";
    switch(unity){
        case MenuModel::TempUnity::CELSIUS:
            result += value;
            result += degree_symbol;
            result += 'C';
        break;
        case MenuModel::TempUnity::FAHRENHEIT:
            result += value * 9 / 5 + 32;
            result += degree_symbol;
            result += 'F';
        break;
    }
    return result;
}