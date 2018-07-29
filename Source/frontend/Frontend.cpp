#include "Frontend.h"

Button* Frontend::_btn1_LockFree_Back;
Button* Frontend::_btn2_Menu_Select;
bool Frontend::btn1State = false;
bool Frontend::btn2State = false;

uint8_t Frontend::menuStackIndex = 0;



Frontend::Frontend( SolderingStationData* solderingStationData,
                    LiquidCrystal* lcd,
                    Button* btn1,
                    Button* btn2,
                    RotaryEncoder* rotaryEncoder) :
    _solderingStationData(solderingStationData),
    _lcd(lcd),
    _rotaryEncoder(rotaryEncoder)
{
    attachButtons(btn1, btn2);
    // pass the lcd and soldering station data to the menus
    MenuItem::attachSolderingStationData(_solderingStationData);
    MenuItem::attachLCD(_lcd);
    // initialize the menu stack with the root menu
    menuStack[0] = &rootMenu;
    menuStack[0]->enteringStack();
}
void Frontend::updateUserInputs(){
    // update rotary encoder
    _solderingStationData->userInput.rotaryIncrement = _rotaryEncoder->update();
    // update buttons and reset them
    _solderingStationData->userInput.btn1_LockFree_Back = btn1State;
    _solderingStationData->userInput.btn2_Menu_Select = btn2State;
    btn1State = false;
    btn2State = false;
}
void Frontend::updateMenu(){
    //handleStack(menuStack[menuStackIndex]->update());
    MenuItem* currentMenu = menuStack[menuStackIndex];
    if(currentMenu != NULL){
        handleStack(currentMenu->update());
    }
}


void Frontend::pop(){
    menuStack[menuStackIndex--]->leavingStack();
}
void Frontend::push(MenuItem* menu){
    if(menu != nullptr){
        menuStack[++menuStackIndex] = menu;
        menuStack[menuStackIndex]->enteringStack();
    }
}


void Frontend::handleStack(MenuItem::StackEvent event){
    switch(event){
        case MenuItem::StackEvent::NOTHING:
        break;
        case MenuItem::StackEvent::POP:
            pop();
        break;
        case MenuItem::StackEvent::PUSH:
            push(getMenuFromLabel(MenuItem::_nextScreen));
        break;
    }
}
MenuItem* Frontend::getMenuFromLabel(MenuItem::MenuScreen menuLabel){
    //todo change this to an iteration based one
    switch(menuLabel){
        case MenuItem::MenuScreen::NULL_MENU:
            return nullptr;
        break;
        case MenuItem::MenuScreen::APP_MENU:
            return &appMenu;
        break;
        case MenuItem::MenuScreen::SELECTION_MENU:
            return &selectionMenu;
        break;
        case MenuItem::MenuScreen::OPTIONS_MENU:
            return &optionsMenu;
        break;
        case MenuItem::MenuScreen::MIN_TEMP_OPTIONS_MENU:
            return &minTempOption;
        break;
        case MenuItem::MenuScreen::MAX_TEMP_OPTIONS_MENU:
            return &maxTempOption;
        break;
        case MenuItem::MenuScreen::TEMP_UNIT_OPTIONS_MENU:
            return &tempUnitOption;
        break;
        default:
            return &appMenu;
        break;
    }
}

void Frontend::attachButtons(Button* btn1, Button* btn2){
    _btn1_LockFree_Back = btn1;
    _btn2_Menu_Select = btn2;
}

ISR(PCINT2_vect){
    _delay_us(2000);
    // read btn 1
    if(Frontend::_btn1_LockFree_Back->isPressed()){ Frontend::btn1State = true; }
    // read btn 2
    if(Frontend::_btn2_Menu_Select->isPressed()){ Frontend::btn2State = true; }
    // buttons will be cleared on read inside updateUserInputs()
}