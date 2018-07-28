//
// Created by carlos on 14/05/2018.
//
#include <avr/io.h>

#include "AnalogPin.h"

AnalogPin::AnalogPin(uint8_t pin, ADCMode mode) : Pin(pin) {
    _pin = pin;
    adcMode = mode;

    // set pin as input
    this->setAsInput();

    // select AVCC as reference
    ADMUX = (1<<REFS0);

    // select correct MUX position
    switch(_pin){
        case ADC0:
            CLR_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);
            break;
        case ADC1:
            CLR_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);
            break;
        case ADC2:
            CLR_BIT(ADMUX,MUX2);SET_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);
            break;
        case ADC3:
            CLR_BIT(ADMUX,MUX2);SET_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);
            break;
        case ADC4:
            SET_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);CLR_BIT(ADMUX,MUX0);
            break;
        case ADC5:
            SET_BIT(ADMUX,MUX2);CLR_BIT(ADMUX,MUX1);SET_BIT(ADMUX,MUX0);
            break;
    }

    // set ADC CLK prescaler (128 by default)
    //todo make it possible to change the prescaler
    SET_BIT(ADCSRA,ADPS2);SET_BIT(ADCSRA,ADPS1);SET_BIT(ADCSRA,ADPS0);

    // enable ADC
    SET_BIT(ADCSRA, ADEN);

    // check adcMode
    switch (adcMode){
        case SINGLE_CONVERSION:
            CLR_BIT(ADCSRA,ADATE);
            break;
        case FREE_RUNNING:
            SET_BIT(ADCSRA,ADATE);
            CLR_BIT(ADCSRB,ADTS2);CLR_BIT(ADCSRB,ADTS1);CLR_BIT(ADCSRB,ADTS0);
            SET_BIT(ADCSRA,ADSC);
            break;
    }
}

uint16_t AnalogPin::getAnalogValue(){
    if(adcMode == SINGLE_CONVERSION){
        // start conversion
        SET_BIT(ADCSRA,ADSC);
        // wait until finished
        while(ADCSRA & 0b01000000){}
    }
    return ADC;
}