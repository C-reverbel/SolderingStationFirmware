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
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);
   // _FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
void Pin::setOutput(bool value) {
    setOutputValue(value);
    //_FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);

}
void Pin::setAsInputPulledUp() {
    *pinStructs[_pin].ddrAddr &= ~(1 << pinStructs[_pin].bit);
    *pinStructs[_pin].portAddr |= (1 << pinStructs[_pin].bit);
    //_FG_CBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
    //_FG_SBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
}
void Pin::setAsInput() {

    *pinStructs[_pin].ddrAddr &= ~(1 << pinStructs[_pin].bit);
    *pinStructs[_pin].portAddr &= ~(1 << pinStructs[_pin].bit);
   // _FG_CBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
   // _FG_CBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
}
void Pin::setOutputLow(){
    *pinStructs[_pin].portAddr &= ~(1 << pinStructs[_pin].bit);
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);
    //_FG_CBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
    //_FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
void Pin::setOutputHigh(){
    *pinStructs[_pin].portAddr |= (1 << pinStructs[_pin].bit);
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);

    //_FG_SBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
    //_FG_SBI(pinStructs[_pin].ddrAddr, pinStructs[_pin].bit);
}
bool Pin::getInput(){
    return *pinStructs[_pin].pin() >> pinStructs[_pin].bit & 1;
}

// Private functions
void Pin::setOutputValueToggle() {
    *pinStructs[_pin].pinAddr |= (1 << pinStructs[_pin].bit);
    //_FG_SBI(pinStructs[_pin].pinAddr, pinStructs[_pin].bit);
}
void Pin::setOutputValue(bool value) {
    if (value)
    {
       // _FG_SBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
        *pinStructs[_pin].portAddr |= (1 << pinStructs[_pin].bit);
    }
    else
    {
        //_FG_CBI(pinStructs[_pin].portAddr, pinStructs[_pin].bit);
        *pinStructs[_pin].portAddr &= ~(1 << pinStructs[_pin].bit);
    }
}


