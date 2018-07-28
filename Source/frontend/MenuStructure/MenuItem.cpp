#include "MenuItem.h"

uint8_t MenuItem::stackIndex = 0;
SolderingStationData* MenuItem::_solderingStationData;

void MenuItem::update(){
    menuStack[stackIndex]->refreshScreen();
    menuStack[stackIndex]->handleUserInput();
}

void MenuItem::pop(){
    menuStack[stackIndex--]->leavingStack();
}
void MenuItem::push(MenuItem* menu){
    menuStack[++stackIndex] = menu;
    menuStack[stackIndex]->enteringStack();
}
void MenuItem::attachSolderingStationData(SolderingStationData* data){
    _solderingStationData = data;
}