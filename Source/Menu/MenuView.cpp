#include "MenuView.h"

#include <avr/interrupt.h>
#include <util/delay.h>

// reserve memory to the static variable to avoid linker errors
LiquidCrystal*  MenuView::_lcd;
Button*         MenuView::_btn1;
Button*         MenuView::_btn2;
RotaryEncoder*  MenuView::_rotaryEnc;

uint16_t MenuView::setTemp = 150;
uint16_t MenuView::mesTemp = 150;
bool MenuView::btn1Val = false;
bool MenuView::btn2Val = false;
int MenuView::rotaryIncr = 0;

ApplicationMenu MenuView::appMenu(&setTemp, &mesTemp);
SelectionMenu MenuView::selectMenu;


MenuView::MenuView(LiquidCrystal *lcd, Button *btn1, Button *btn2, RotaryEncoder *rotaryEnc){
    attachLCD(lcd);
    attachButtons(btn1, btn2);
    attachRotaryEncoder(rotaryEnc);

    currentMenu = &appMenu;
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
    currentMenu->refreshScreen();
}
Menu::userIO MenuView::getIOValues(){
    Menu::userIO result;
    // update rotary encoder
    rotaryIncr = _rotaryEnc->update();
    result.rotIncr = rotaryIncr;
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
    if(MenuView::_btn1->isPressed()){
        MenuView::btn1Val = true;
    }
    // read btn 2
    if(MenuView::_btn2->isPressed()){
        MenuView::btn2Val = true;
    }
    // buttons will be cleared on read inside updateFromBtns() function
}