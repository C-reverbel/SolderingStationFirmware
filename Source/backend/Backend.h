/*
 * - Read soldering iron temperature
 * - Compute PID temperature control
 * - Set corresponding PWM value
 */
#ifndef SOLDERINGSTATIONFIRMWARE_BACKEND_H
#define SOLDERINGSTATIONFIRMWARE_BACKEND_H

#include "utils/PID/PID_v1.h"
#include "utils/GPIO/FastPWMPin.h"
#include "utils/GPIO/AnalogPin.h"
#include "SolderingStationData.h"

class Backend {
private:
    SolderingStationData& _solderingStationData;
    AnalogPin& _ptcPin;
    FastPWMPin& _pwmPin;
    PID myPID;

public:
    Backend(SolderingStationData& solderingStationData, AnalogPin& ptcPin, FastPWMPin& pwmPin);
    void readIronTemperature();
    void updateTemperatureController();
};

#endif //SOLDERINGSTATIONFIRMWARE_BACKEND_H
