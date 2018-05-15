//
// Created by carlos on 14/05/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_ANALOGPIN_H
#define SOLDERINGSTATIONFIRMWARE_ANALOGPIN_H

#include "GPIO.h"

#define ADC0 IO_C0
#define ADC1 IO_C1
#define ADC2 IO_C2
#define ADC3 IO_C3
#define ADC4 IO_C4
#define ADC5 IO_C5

enum ADCMode{
    SINGLE_CONVERSION,
    FREE_RUNNING,
};

class AnalogPin : public Pin{

public:
    ADCMode adcMode;

    AnalogPin(uint8_t pin, ADCMode mode = ADCMode::SINGLE_CONVERSION);

    uint16_t getAnalogValue();


};


#endif //SOLDERINGSTATIONFIRMWARE_ANALOGPIN_H
