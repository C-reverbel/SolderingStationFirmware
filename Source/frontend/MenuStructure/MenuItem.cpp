#include "MenuItem.h"

SolderingStationData* MenuItem::_solderingStationData;
MenuItem::StackEvent MenuItem::_stackEvent = MenuItem::StackEvent::NOTHING;
MenuItem::MenuScreen MenuItem::_nextScreen = MenuItem::MenuScreen::APP_MENU;
LiquidCrystal* MenuItem::_lcd;

MenuItem::StackEvent MenuItem::update(){
    _stackEvent = StackEvent::NOTHING;
    handleUserInputTask();
    refreshScreenTask();
    return _stackEvent;
}
void MenuItem::enteringStack(){
    _stackEvent = MenuItem::StackEvent::NOTHING;
    enteringStackTask();
}
void MenuItem::leavingStack(){
    leavingStackTask();
}


void MenuItem::attachSolderingStationData(SolderingStationData* data){
    _solderingStationData = data;
}
void MenuItem::attachLCD(LiquidCrystal* lcd){
    _lcd = lcd;
    _lcd->begin(8,2);
    _lcd->clear();
    _lcd->setCursor(0,0);
}