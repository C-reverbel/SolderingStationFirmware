#include "Button.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>


Button::Button(const uint8_t &pin) : Pin(pin) {
    this->setAsInputPulledUp();
    this->setInterruptOnPinChange();
}

bool Button::isPressed(){
    return !(this->getInput());
}