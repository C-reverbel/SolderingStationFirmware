#include <string.h>
#include <util/delay.h>

#include "ApplicationMenu.h"

ApplicationMenu::ApplicationMenu(uint16_t* setTemp, uint16_t* mesTemp) {
    this->mesTemp = mesTemp;
    this->setTemp = setTemp;
}

// HIGH LEVEL FUNCTIONS
Menu::MenuScreen ApplicationMenu::updateFromBtns() {
    // get buttons input and compute what to do with it
    if(*_btn1){         // lock-unlock rotary encoder
        _delay_us(500);
        *_locked_rotary_flag = !(*_locked_rotary_flag);
        *_btn1 = false;
    }else if(*_btn2){   // access selection menu
        _delay_us(500);
        *_btn2 = false;
        return MenuScreen::SELECTION_MENU;
    }
    return MenuScreen::APP_MENU;
}
void ApplicationMenu::refreshScreen() {
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); printSetTemp(*setTemp,tempUnity);
    // print second line
    _lcd->setCursor(0,1); printMesTemp(*mesTemp,tempUnity);
    //TODO change locked symbol
    if(*_locked_rotary_flag){
        _lcd->setCursor(7,0); _lcd->print('&');
    }
}

// MID LEVEL FUNCTIONS
void ApplicationMenu::printSetTemp(uint16_t temperature, TempUnity unity) {
    _lcd->print("S:");_lcd->print(getTempString(*setTemp,unity));
}
void ApplicationMenu::printMesTemp(uint16_t temperature, TempUnity unity) {
    _lcd->print("M:");_lcd->print(getTempString(*mesTemp,unity));
}

// LOW LEVEL FUNCTIONS
String ApplicationMenu::getTempString(uint16_t value, ApplicationMenu::TempUnity unity) {
    String result = "";
    switch(unity){
        case CELSIUS:
            result += value;
            result += degree_symbol;
            result += 'C';
            break;
        case FAHRENHEIT:
            result += (value * 9 / 5 + 32);
            result += degree_symbol;
            result += 'F';
            break;
    }
    return result;
}