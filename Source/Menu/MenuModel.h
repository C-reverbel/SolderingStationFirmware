#ifndef SOLDERINGSTATIONFIRMWARE_MENUMODEL_H
#define SOLDERINGSTATIONFIRMWARE_MENUMODEL_H


#include <avr/io.h>

#include "PID/PID_v1.h"
#include "GPIO/FastPWMPin.h"
#include "GPIO/AnalogPin.h"
#include "Menu.h"

class MenuModel {
public:
    enum TempUnity {
        CELSIUS,
        FAHRENHEIT
    } tempUnity;
    //todo save the struct on eeprom
    struct Options{
        MenuModel::TempUnity tempUnity = MenuModel::TempUnity::CELSIUS;
        Menu::MenuScreen defaultScreen = Menu::MenuScreen::APP_MENU;
        bool lockedRotaryFlag = false;
        double defaultTemp = 300.0;
        //todo add calibration variables
    } options;

    Menu::MenuScreen lastScreen;
    Menu::MenuScreen currentScreen;

    FastPWMPin* _pwmOut;
    AnalogPin* _ptcRead;

    double pwmVal_PIDOut;
    double mesTemp_PIDIn;
    double setTemp_PIDSetpoint;
    PID myPID;

public:
    MenuModel(AnalogPin* ptcRead, FastPWMPin* pwmOut);
    double measureTemp();
    //todo handle soldering station options
    void loadOptions();
    void storeOptions();

};


#endif //SOLDERINGSTATIONFIRMWARE_MENUMODEL_H
