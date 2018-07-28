//
// Created by carlos on 11/05/2018.
//


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

#ifndef SOLDERINGSTATIONFIRMWARE_PWMPIN_H
#define SOLDERINGSTATIONFIRMWARE_PWMPIN_H

#include "GPIO.h"

#define OC0A 22
#define OC0B 21
#define OC1A 1
#define OC1B 2
#define OC2A 3
#define OC2B 19


class FastPWMPin : public Pin{
private:
    uint16_t timer1Prescaler [6] = {1,1,8,64,256,1024};
    uint16_t timer2Prescaler [8] = {1,1,8,32,64,128,256,1024};



public:
    struct PWMParameters{
        uint8_t prescaler;
        uint8_t bitResolution;
        uint16_t top;
        double frequency;
    } pwmParameters;

    enum PWMMode{
        NORMAL,
        CTC,
        FAST,
        PHASE_CORRECT,
        PHASE_FREQ_CORRECT,
    } pwmMode;
    enum CompareMatch{
        DISCONNECTED = 0x00,
        TOGGLE = 0x01,
        CLEAR = 0x02,
        SET = 0x03,
    } compareMatch;

private:
    bool setPWMRegisters(uint8_t pin);

public:
    FastPWMPin(uint8_t pin);
    bool startPWM(double pwmFreq);
    void setPWMValue(double percent);


};


#endif //SOLDERINGSTATIONFIRMWARE_PWMPIN_H
