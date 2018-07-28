//
// Created by carlos on 10/05/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_ROTARYENCODER_H
#define SOLDERINGSTATIONFIRMWARE_ROTARYENCODER_H

#include "utils/GPIO/GPIO.h"


class RotaryEncoder {

public:
    Pin* rotA;
    Pin* rotB;
    uint8_t rotSpeed;

    enum RotaryState{
        NONE,
        UP,
        DOWN,
        UP_FAST,
        DOWN_FAST
    } rotaryState = NONE;


public:
    RotaryEncoder(Pin* rotA, Pin* rotB);

    void updateState();
    int update();



};


#endif //SOLDERINGSTATIONFIRMWARE_ROTARYENCODER_H
