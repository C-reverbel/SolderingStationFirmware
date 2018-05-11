//
// Created by carlos on 10/05/2018.
//


#define ROTARY_ZERO 128
#define ROTARY_UP_FAST_THRESHOLD 138
#define ROTARY_DOWN_FAST_THRESHOLD 118


#include "RotaryEncoder.h"
#include <avr/interrupt.h>
#include <util/delay.h>




static RotaryEncoder* thisRotaryEncoder = nullptr;

ISR(PCINT0_vect){
    _delay_us(100);
    uint8_t stateA = thisRotaryEncoder->rotA->getInput();
    uint8_t stateB = thisRotaryEncoder->rotB->getInput();
    if (stateA == stateB) {
        thisRotaryEncoder->rotSpeed--;
    } else {
        thisRotaryEncoder->rotSpeed++;
    }


    if(thisRotaryEncoder->rotSpeed == 255) thisRotaryEncoder->rotSpeed = ROTARY_UP_FAST_THRESHOLD;
    else if(thisRotaryEncoder->rotSpeed == 0) thisRotaryEncoder->rotSpeed = ROTARY_DOWN_FAST_THRESHOLD;
}


RotaryEncoder::RotaryEncoder(Pin* rotA, Pin* rotB) {
    rotSpeed = ROTARY_ZERO;

    this->rotA = rotA;
    this->rotB = rotB;

    this->rotA->setAsInputPulledUp();
    this->rotB->setAsInputPulledUp();

    this->rotA->setInterruptOnPinChange();

    thisRotaryEncoder = this;

}

// temp function
void RotaryEncoder::updateState(){
    uint8_t actualSpeed = rotSpeed;
    rotSpeed = ROTARY_ZERO;
    if(actualSpeed >= ROTARY_UP_FAST_THRESHOLD) rotaryState = UP_FAST;
    else if (actualSpeed > ROTARY_ZERO) rotaryState = UP;
    else if (actualSpeed <= ROTARY_DOWN_FAST_THRESHOLD) rotaryState = DOWN_FAST;
    else if (actualSpeed < ROTARY_ZERO) rotaryState = DOWN;
    else rotaryState = NONE;
}


