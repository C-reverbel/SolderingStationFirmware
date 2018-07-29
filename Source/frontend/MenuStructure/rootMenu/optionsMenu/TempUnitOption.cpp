#include "TempUnitOption.h"

void TempUnitOption::handleUserInputTask(){
    // rotary encoder
    int temp = _solderingStationData->userInput.rotaryIncrement;
    if(temp > 0 && (selectableUnitIndex < nbOfOptions - 1)){
        selectableUnitIndex++;
    }else if(temp < 0 && selectableUnitIndex > 0){
        selectableUnitIndex--;
    }
    // btn1
    if(_solderingStationData->userInput.btn1_LockFree_Back){
        _stackEvent = StackEvent::POP;
        _solderingStationData->tempUnity = defaultTempUnit;
    }
    // btn2
    if(_solderingStationData->userInput.btn2_Menu_Select){
        _solderingStationData->tempUnity = selectableUnitList[selectableUnitIndex];
        MenuItem::_stackEvent = MenuItem::StackEvent::POP;
    }
}
void TempUnitOption::refreshScreenTask(){
    printSelectedUnit(selectableUnitStringsList[selectableUnitIndex]);
}
void TempUnitOption::enteringStackTask(){
    defaultTempUnit = _solderingStationData->tempUnity;
}
void TempUnitOption::leavingStackTask(){
    //todo update eeprom
}

void TempUnitOption::printSelectedUnit(String unit){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); _lcd->print(unit_text);
    // print second line
    _lcd->setCursor(0,1); _lcd->print('<');
    _lcd->setCursor(2,1); _lcd->print(unit);
    _lcd->setCursor(7,1); _lcd->print('>');
}