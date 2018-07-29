#include "MinTempOption.h"

void MinTempOption::handleUserInputTask(){
    // rotary encoder
    int temp = _solderingStationData->minTempInCelsius + _solderingStationData->userInput.rotaryIncrement;
    if((temp < 0)){
        _solderingStationData->minTempInCelsius = 0;
    }else if(temp > _solderingStationData->maxTempInCelsius){
        _solderingStationData->minTempInCelsius = _solderingStationData->maxTempInCelsius;
    }else{
        _solderingStationData->minTempInCelsius = temp;
    }
    // btn1
    if(_solderingStationData->userInput.btn1_LockFree_Back){
        _stackEvent = StackEvent::POP;
        _solderingStationData->minTempInCelsius = defaultMinTemp;
    }
    // btn2
    if(_solderingStationData->userInput.btn2_Menu_Select){
        MenuItem::_stackEvent = MenuItem::StackEvent::POP;
    }
}
void MinTempOption::refreshScreenTask(){
    printSelectedTemperature(_solderingStationData->minTempInCelsius);
}
void MinTempOption::enteringStackTask(){
    defaultMinTemp = _solderingStationData->minTempInCelsius;
}
void MinTempOption::leavingStackTask(){
    //todo update eeprom
}

void MinTempOption::printSelectedTemperature(uint16_t temperature){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); _lcd->print("MIN_TEMP");
    // print second line
    _lcd->setCursor(0,1); _lcd->print('<');
    _lcd->setCursor(2,1); _lcd->print(getTempString(temperature, _solderingStationData->tempUnity));
    _lcd->setCursor(7,1); _lcd->print('>');
}

String MinTempOption::getTempString(uint16_t value, TempUnit unity){
    String result = "";
    switch(unity){
        case TempUnit::CELSIUS:
            result += value;
            result += degree_symbol;
            result += 'C';
            break;
        case TempUnit::FAHRENHEIT:
            result += value * 9 / 5 + 32;
            result += degree_symbol;
            result += 'F';
            break;
    }
    return result;
}