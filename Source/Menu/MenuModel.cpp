#include "MenuModel.h"

MenuModel::MenuModel(AnalogPin *ptcRead, FastPWMPin *pwmOut) :
        myPID(&mesTemp_PIDIn, &pwmVal_PIDOut, &setTemp_PIDSetpoint, 2, 5, 1, DIRECT)
{
    _ptcRead = ptcRead;
    _pwmOut = pwmOut;

    _pwmOut->startPWM(10e3);
    _pwmOut->setOutputLow();

    lastScreen = Menu::MenuScreen::APP_MENU;
    currentScreen = Menu::MenuScreen::APP_MENU;

    myPID.SetOutputLimits(0, 100);
}

double MenuModel::measureTemp(){
    //todo change constants to variables
    return 0.666 * MenuModel::_ptcRead->getAnalogValue() - 152.4;
}

void MenuModel::loadOptions() {
    //todo check eeprom for lattest options
}
void MenuModel::storeOptions() {
    //todo write eeprom with lattest options
}