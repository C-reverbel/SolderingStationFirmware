//
// Created by carlos on 08/05/2018.
//

#include "ApplicationMenu.h"

// HIGH LEVEL FUNCTIONS
void ApplicationMenu::update() {

}
void ApplicationMenu::refreshScreen() {
    // print first line
    _lcd->setCursor(0,0); printSetTemp();
    // print second line
    _lcd->setCursor(0,1); printMesTemp();
    //TODO include locked symbol

}


// MID LEVEL FUNCTIONS
void ApplicationMenu::printSetTemp() {
    _lcd->print("S:");_lcd->print(convertedTemp(setTemp));_lcd->print(degree);_lcd->print(getTempUnity());
}
void ApplicationMenu::printMesTemp() {
    _lcd->print("M:");_lcd->print(convertedTemp(mesTemp));_lcd->print(degree);_lcd->print(getTempUnity());
}


// LOW LEVEL FUNCTIONS
char ApplicationMenu::getTempUnity() {
    switch (tempUnity){
        case CELSIUS:
            return 'C';
            break;
        case FAHRENHEIT:
            return 'F';
            break;
    }
    return 'E';
}
uint16_t ApplicationMenu::convertedTemp(uint16_t temp) {
    switch (tempUnity){
        case CELSIUS:
            return temp;
            break;
        case FAHRENHEIT:
            return (temp * 9) / 5 + 32;
            break;
    }
}