//
// Created by carlos on 17/04/2018.
//

#include <avr/io.h>
#include <avr/interrupt.h>

#include "GPIO.h"

Pin::Pin(uint8_t pin = 15){
    _pin = pin;
}



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
}
void Pin::setOutput(bool value) {
    setOutputValue(value);
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);
}
void Pin::setAsInputPulledUp() {
    *pinStructs[_pin].ddrAddr &= ~(1 << pinStructs[_pin].bit);
    *pinStructs[_pin].portAddr |= (1 << pinStructs[_pin].bit);
}
void Pin::setAsInput() {
    *pinStructs[_pin].ddrAddr &= ~(1 << pinStructs[_pin].bit);
    *pinStructs[_pin].portAddr &= ~(1 << pinStructs[_pin].bit);
}
void Pin::setOutputLow(){
    *pinStructs[_pin].portAddr &= ~(1 << pinStructs[_pin].bit);
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);
}
void Pin::setOutputHigh(){
    *pinStructs[_pin].portAddr |= (1 << pinStructs[_pin].bit);
    *pinStructs[_pin].ddrAddr |= (1 << pinStructs[_pin].bit);
}
bool Pin::getInput(){
    return *pinStructs[_pin].pin() >> pinStructs[_pin].bit & 1;
}

void Pin::setInterruptOnPinChange() {
    sei();
    if(_pin < 8){
        // PCINT[0:7] <=> PORTB[0:7]
        // Use ISR(PCINT0_vect)
        PCICR |= (1 << PCIE0);
        PCMSK0 |= (1 << _pin);
    } else if(_pin < 16){
        // PCINT[8:14] <=> PORTC[0:6]
        // Use ISR(PCINT1_vect)
        PCICR |= (1 << PCIE1);
        PCMSK1 |= (1 << (_pin-8));
    } else if (_pin < 24){
        // PCINT[16:23] <=> PORTD[0:7]
        // Use ISR(PCINT2_vect)
        PCICR |= (1 << PCIE2);
        PCMSK2 |= (1 << (_pin-16));
    }
}

void Pin::clearInterruptOnPinChange() {
    if(_pin < 8){
        // PCINT[0:7] <=> PORTB[0:7]
        PCICR &= ~(1 << PCIE0);
        PCMSK0 &= ~(1 << _pin);
    } else if(_pin < 16){
        // PCINT[8:14] <=> PORTC[0:6]
        PCICR &= ~(1 << PCIE1);
        PCMSK1 &= ~(1 << (_pin-8));
    } else if (_pin < 24){
        // PCINT[16:23] <=> PORTD[0:7]
        PCICR &= ~(1 << PCIE2);
        PCMSK2 &= ~(1 << (_pin-16));
    }
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


