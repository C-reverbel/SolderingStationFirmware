#include "SelectionMenu.h"

void SelectionMenu::handleUserInputTask(){
    // btn1
    if(_solderingStationData->userInput.btn1_LockFree_Back){
        _stackEvent = StackEvent::POP;
    }
    // btn2
    if(_solderingStationData->userInput.btn2_Menu_Select){
        MenuItem::_nextScreen = selectableMenusList[selectableMenusIndex];  // tells the system to push selected menu
        MenuItem::_stackEvent = MenuItem::StackEvent::POP;                  // back to the root menu
    }
    // rotary encoder
    int temp = _solderingStationData->userInput.rotaryIncrement;
    if(temp > 0 && (selectableMenusIndex < nbOfSelectableMenus - 1)){
        selectableMenusIndex++;
    }else if(temp < 0 && selectableMenusIndex > 0){
        selectableMenusIndex--;
    }
}
void SelectionMenu::refreshScreenTask(){
    printMenuSelectin(selectableMenusStringsList[selectableMenusIndex]);
}
void SelectionMenu::enteringStackTask(){
    _nextScreen = MenuScreen::APP_MENU;
}
void SelectionMenu::leavingStackTask(){

}

void SelectionMenu::printMenuSelectin(String selectedMenu){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); _lcd->print('<');
    _lcd->setCursor(2,0); _lcd->print(selectedMenu);
    _lcd->setCursor(7,0); _lcd->print('>');
    // print second line
    _lcd->setCursor(0,1); _lcd->print('<');
    _lcd->setCursor(2,1); _lcd->print(menu_text);
    _lcd->setCursor(7,1); _lcd->print('>');
}