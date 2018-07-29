#include "OptionsMenu.h"

void OptionsMenu::handleUserInputTask(){
    // btn1
    if(_solderingStationData->userInput.btn1_LockFree_Back){
        MenuItem::_nextScreen = MenuScreen::APP_MENU;
        _stackEvent = StackEvent::POP;
    }
    // btn2
    if(_solderingStationData->userInput.btn2_Menu_Select){
        MenuItem::_nextScreen = selectableOptionsList[selectableOptionsIndex];  // tells the system to push selected menu
        MenuItem::_stackEvent = MenuItem::StackEvent::PUSH;                     // goto next screen
    }
    // rotary encoder
    int temp = _solderingStationData->userInput.rotaryIncrement;
    if(temp > 0 && (selectableOptionsIndex < nbOfOptions - 1)){
        selectableOptionsIndex++;
    }else if(temp < 0 && selectableOptionsIndex > 0){
        selectableOptionsIndex--;
    }
}
void OptionsMenu::refreshScreenTask(){
    printOptionSelection(selectableOptionsStringsList[selectableOptionsIndex]);
}
void OptionsMenu::enteringStackTask(){
    _nextScreen = MenuScreen::APP_MENU;
}
void OptionsMenu::leavingStackTask(){
    //todo save new preferences on eeprom
}

void OptionsMenu::printOptionSelection(String selectedOption){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); _lcd->print('<');
    _lcd->setCursor(2,1); _lcd->print(option_text);
    _lcd->setCursor(7,0); _lcd->print('>');
    // print second line
    _lcd->setCursor(0,1); _lcd->print('<');
    _lcd->setCursor(2,0); _lcd->print(selectedOption);
    _lcd->setCursor(7,1); _lcd->print('>');
}