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
        uint16_t defaultTemp = 150;
        //todo add calibration variables
    } options;

    uint16_t setTemp;
    uint16_t mesTemp;

    Menu::MenuScreen lastScreen;
    Menu::MenuScreen currentScreen;

    FastPWMPin* _pwmOut;
    AnalogPin* _ptcRead;

    double pwmVal;
    double pidIn;
    double pidOut;
    double pidSetpoint;
    PID myPID;

public:
    MenuModel(AnalogPin* ptcRead, FastPWMPin* pwmOut);
    uint16_t convertTemp(TempUnity unity);
    double measureTemp();
    //todo handle soldering station options
    void loadOptions();
    void storeOptions();

};


#endif //SOLDERINGSTATIONFIRMWARE_MENUMODEL_H
