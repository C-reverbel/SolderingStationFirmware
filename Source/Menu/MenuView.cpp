#include "MenuView.h"

#include <avr/interrupt.h>
#include <util/delay.h>

// reserve memory to the static variables to avoid linker errors
Button*         MenuView::_btn1;
Button*         MenuView::_btn2;
RotaryEncoder*  MenuView::_rotaryEnc;

bool MenuView::btn1Val = false;
bool MenuView::btn2Val = false;


MenuView::MenuView(LiquidCrystal *lcd, Button *btn1, Button *btn2, RotaryEncoder *rotaryEnc) {
    attachLCD(lcd);
    attachButtons(btn1, btn2);
    attachRotaryEncoder(rotaryEnc);
}

void MenuView::attachLCD(LiquidCrystal* lcd){
    Menu::attachLCD(lcd);
}
void MenuView::attachButtons(Button* btn1, Button* btn2){
    _btn1 = btn1;
    _btn2 = btn2;
}
void MenuView::attachRotaryEncoder(RotaryEncoder* rotaryEnc){
    _rotaryEnc = rotaryEnc;
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
void MenuView::resetSelectionMenu(){
    highlightedMenuIndex = 0;
}

ISR(PCINT2_vect){
    _delay_us(1800);
    // read btn 1
    if(MenuView::_btn1->isPressed())
        MenuView::setBtn1Val(true);
    // read btn 2
    if(MenuView::_btn2->isPressed())
        MenuView::setBtn2Val(true);
    // buttons will be cleared on read inside updateFromBtns() function
}