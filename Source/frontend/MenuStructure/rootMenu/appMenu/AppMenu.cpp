#include "AppMenu.h"

void AppMenu::handleUserInputTask(){
    // btn1
    if(_solderingStationData->userInput.btn1_LockFree_Back){
        _solderingStationData->rotaryEncoderLocked = !_solderingStationData->rotaryEncoderLocked;
    }
    // btn2
    if(_solderingStationData->userInput.btn2_Menu_Select){
        MenuItem::_nextScreen = MenuItem::MenuScreen::SELECTION_MENU;   // tells the system to push selection menu
        MenuItem::_stackEvent = MenuItem::StackEvent::POP;              // back to the root menu
    }
    // rotary encoder
    if(!_solderingStationData->rotaryEncoderLocked){
        _solderingStationData->incrementSetTempWithinLimits(_solderingStationData->userInput.rotaryIncrement);
    }


}
void AppMenu::refreshScreenTask(){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0);
    printSetTemp(_solderingStationData->setTemperatureInCelsius, _solderingStationData->tempUnity);
    // print second line
    _lcd->setCursor(0,1);
    printMesTemp(_solderingStationData->mesTemperatureInCelsius, _solderingStationData->tempUnity);
    //TODO change locked symbol
    if(_solderingStationData->rotaryEncoderLocked){
        _lcd->setCursor(7,0); _lcd->print('&');
    }

}
void AppMenu::enteringStackTask(){

}
void AppMenu::leavingStackTask(){

}

void   AppMenu::printSetTemp(double temperature, TempUnit unity){
    _lcd->print("S:");_lcd->print(getTempString(temperature,unity));
}
void   AppMenu::printMesTemp(double temperature, TempUnit unity){
    _lcd->print("M:");_lcd->print(getTempString(temperature,unity));
}
String AppMenu::getTempString(double value, TempUnit unity){
    String result = "";
    switch(unity){
        case TempUnit::CELSIUS:
            result += (uint16_t) value;
            result += degree_symbol;
            result += 'C';
            break;
        case TempUnit::FAHRENHEIT:
            result += (uint16_t) value * 9 / 5 + 32;
            result += degree_symbol;
            result += 'F';
            break;
    }
    return result;
}

