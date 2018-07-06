//
// Created by carlos on 08/05/2018.
//

#include <string.h>

#include "ApplicationMenu.h"

ApplicationMenu::ApplicationMenu(uint16_t* setTemp, uint16_t* mesTemp){
    this->mesTemp = mesTemp;
    this->setTemp = setTemp;
}

// HIGH LEVEL FUNCTIONS
void ApplicationMenu::update() {
    //TODO update members of the class
}
void ApplicationMenu::refreshScreen() {
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); printSetTemp(*setTemp,tempUnity);
    // print second line
    _lcd->setCursor(0,1); printMesTemp(*mesTemp,tempUnity);
    //TODO include locked symbol
}

// MID LEVEL FUNCTIONS
void ApplicationMenu::printSetTemp(uint16_t temperature, TempUnity unity) {
    _lcd->print("S:");_lcd->print(getTempString(*setTemp,unity));
}
void ApplicationMenu::printMesTemp(uint16_t temperature, TempUnity unity) {
    _lcd->print("M:");_lcd->print(getTempString(*mesTemp,unity));
}

// LOW LEVEL FUNCTIONS
String ApplicationMenu::getTempString(uint16_t value, ApplicationMenu::TempUnity unity){
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