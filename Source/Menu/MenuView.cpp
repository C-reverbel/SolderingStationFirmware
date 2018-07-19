#include "MenuView.h"

#include <avr/interrupt.h>
#include <util/delay.h>

// reserve memory to the static variables to avoid linker errors
LiquidCrystal*  MenuView::_lcd;
Button*         MenuView::_btn1;
Button*         MenuView::_btn2;
RotaryEncoder*  MenuView::_rotaryEnc;

uint16_t MenuView::setTemp = 150;
uint16_t MenuView::mesTemp = 150;

Menu::MenuScreen MenuView::currentScreen = Menu::MenuScreen::APP_MENU;
Menu::MenuScreen MenuView::lastScreen = Menu::MenuScreen::APP_MENU;

bool MenuView::btn1Val = false;
bool MenuView::btn2Val = false;

ApplicationMenu MenuView::appMenu(&setTemp, &mesTemp);
SelectionMenu MenuView::selectMenu;


MenuView::MenuView(LiquidCrystal *lcd, Button *btn1, Button *btn2, RotaryEncoder *rotaryEnc){
    attachLCD(lcd);
    attachButtons(btn1, btn2);
    attachRotaryEncoder(rotaryEnc);
}

void MenuView::attachLCD(LiquidCrystal* lcd){
    _lcd = lcd;
    _lcd->begin(8,2);
    _lcd->clear();
    _lcd->setCursor(0,0);
}
void MenuView::attachButtons(Button* btn1, Button* btn2){
    _btn1 = btn1;
    _btn2 = btn2;
}
void MenuView::attachRotaryEncoder(RotaryEncoder* rotaryEnc){
    _rotaryEnc = rotaryEnc;
}

void MenuView::refreshScreen() {
    switch(currentScreen){
        case Menu::MenuScreen::APP_MENU:
            appMenu.refreshScreen();
        break;
        case Menu::MenuScreen::SELECTION_MENU:
            selectMenu.refreshScreen();
        break;
    }
}
Menu::userIO MenuView::getIOValues(){
    Menu::userIO result;
    // update rotary encoder
    result.rotIncr = _rotaryEnc->update();
    // update buttons and reset them
    result.btn1 = getBtn1Val();
    result.btn2 = getBtn2Val();
    setBtn1Val(false);
    setBtn2Val(false);
    return result;
}


ISR(PCINT2_vect){
    _delay_us(800);
    // read btn 1
    if(MenuView::_btn1->isPressed())
        MenuView::setBtn1Val(true);
    // read btn 2
    if(MenuView::_btn2->isPressed())
        MenuView::setBtn2Val(true);
    // buttons will be cleared on read inside updateFromBtns() function
}