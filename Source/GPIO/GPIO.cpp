//
// Created by carlos on 17/04/2018.
//

#include "GPIO.h"

Pin::Pin(uint8_t pin = 21){
    _pin = pin;
}

//Pin Pin::none = Pin(21);


// Public functions
bool Pin::isValidPin() {
    if(_pin == IO_NONE)
        return 0;
    else
        return 1;
}
void Pin::setOutputToggle() {
    setOutputValueToggle();
    _FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
void Pin::setOutput(bool value) {
    setOutputValue(value);
    _FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
void Pin::setAsInputPulledUp() {
    _FG_CBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
    _FG_SBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
}
void Pin::setAsInput() {
    _FG_CBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
    _FG_CBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
}
void Pin::setOutputLow(){
    _FG_CBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
    _FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
void Pin::setOutputHigh(){
    _FG_SBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
    _FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
bool Pin::getInput(){
    return *pinStructs[_pin].pin() >> pinStructs[_pin].bit & 1;
}

// Private functions
void Pin::setOutputValueToggle() {
    _FG_SBI(pinStructs[_pin].pinAddr, pinStructs[_pin].bit);
}
void Pin::setOutputValue(bool value) {
    if (value)
    {
        _FG_SBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
    }
    else
    {
        _FG_CBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
    }
}


