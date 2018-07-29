#include "Backend.h"


Backend::Backend( SolderingStationData& solderingStationData,
                  AnalogPin& ptcPin,
                  FastPWMPin& pwmPin) :
    myPID( &solderingStationData.mesTemperatureInCelsius,
           &solderingStationData.pwmValueInPercent,
           &solderingStationData.setTemperatureInCelsius, 2, 5, 1, DIRECT),
    _solderingStationData(solderingStationData),
    _ptcPin(ptcPin),
    _pwmPin(pwmPin)
{
    _pwmPin.startPWM(10e3);
    _pwmPin.setOutputLow();

    myPID.SetOutputLimits(0, 100);
}
void Backend::readIronTemperature(){
    //todo change constants to variables
    _solderingStationData.mesTemperatureInCelsius = 0.666 * _ptcPin.getAnalogValue() - 152.4;
}
void Backend::updateTemperatureController(){
    myPID.Compute();
    _pwmPin.setPWMValue(_solderingStationData.pwmValueInPercent);
}
