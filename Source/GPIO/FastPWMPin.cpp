//
// Created by carlos on 11/05/2018.
//

#include <math.h>

#include "FastPWMPin.h"

FastPWMPin::FastPWMPin(uint8_t pin) : Pin(pin){
    _pin = pin;
    pwmParameters.bitResolution = 0;
}

bool FastPWMPin::startPWM(double pwmFreq){
    pwmParameters.frequency = pwmFreq;
    double clkRation = F_CPU/pwmFreq;
    uint8_t i = 1;

    // get prescaler and PWM resolution
    if(clkRation <= 1) {
        pwmParameters.bitResolution = 0;
        return false;
    }
    pwmParameters.bitResolution = floor(log(clkRation)/log(2));
    while(pwmParameters.bitResolution > 16) {
        if(timer1Prescaler[i] != 1024) i++;
        else {
            pwmParameters.bitResolution = 0;
            return false;
        }
        pwmParameters.bitResolution = floor(log(clkRation / timer1Prescaler[i])/log(2));
    }
    pwmParameters.prescaler = i;
    // calculate timer offset based on required frequency
    pwmParameters.top = (uint16_t) clkRation / timer1Prescaler[pwmParameters.prescaler];


    setPWMRegisters(_pin);


    // calculate values for registers based on pwmMode and pwmFeq
    // init correct timer (0, 1 or 2)
    // if it is valid, update registers and return true
    // if it is invalid, return false
    return true;
}

void FastPWMPin::setPWMValue(float percent){
    // select correct OCR
    if(percent){
        // enable PWM
        TCCR1A |=  (1 << COM1B1);
        TCCR1A &=  ~(1 << COM1B0);
        // set value
        OCR1B = percent * pwmParameters.top / 100;
    } else {
        // disable PWM
        TCCR1A &=  ~(1 << COM1B1);
        TCCR1A &=  ~(1 << COM1B0);
        // set value
        this->setOutputLow();
    }
}

// PRIVATE FUNCTIONS
bool FastPWMPin::setPWMRegisters(uint8_t pin){
/*
PWM PINS MAPPING ON ATMEGA328P
----------------------------------------------------
GPIO  | OUTPUT COMPARE REG  | TIMER   | Arduino  PIN
----------------------------------------------------
PD6   | OC0A                | TIMER 0 | 6
PD5   | OC0B                | TIMER 0 | 5
PB1   | OC1A                | TIMER 1 | 9
PB2   | OC1B                | TIMER 1 | 10
PB3   | OC2A                | TIMER 2 | 11
PD3   | OC2B                | TIMER 2 | 3
----------------------------------------------------
*/
    if(pin == OC0A){
//        TCCR0A
//        TCCR0B
//        TCNT0
//        TIMSK0

    } else if (pin == OC0B){

    } else if (pin == OC1A){
        // non-inverting Mode
        TCCR1A |=   (1 << COM1A1);
        TCCR1A &=  ~(1 << COM1A0);
        // Fast PWM Mode - TOP = ICR1
        TCCR1A &= ~(1 << WGM10);
        TCCR1A |=  (1 << WGM11);
        TCCR1B |=  (1 << WGM12);
        TCCR1B |=  (1 << WGM13);
        // set ICR1 and prescaler based on calculated resolution
        ICR1 = pwmParameters.top;
        TCCR1B |= pwmParameters.prescaler;

    } else if (pin == OC1B){
        // non-inverting Mode
        TCCR1A |=   (1 << COM1B1);
        TCCR1A &=  ~(1 << COM1B0);
        // Fast PWM Mode - TOP = ICR1
        TCCR1A &= ~(1 << WGM10);
        TCCR1A |=  (1 << WGM11);
        TCCR1B |=  (1 << WGM12);
        TCCR1B |=  (1 << WGM13);
        // set ICR1 (TOP) and clk prescaler based on calculated resolution
        ICR1 = pwmParameters.top;
        TCCR1B |= pwmParameters.prescaler;

    } else if (pin == OC2A){

    } else if (pin == OC2B){

    } else {
        return false;
    }
    // set timer offset based on frequency

    return true;
}