#ifndef SOLDERINGSTATIONFIRMWARE_SOLDERINGSTATIONDATA_H
#define SOLDERINGSTATIONFIRMWARE_SOLDERINGSTATIONDATA_H

#include <avr/io.h>

// after creating a new menu, add it here
enum MenuScreen{
    SELECTION_MENU,
    APP_MENU,
    OPTIONS_MENU
};
enum TempUnit {
    CELSIUS,
    FAHRENHEIT
};
struct StartupOptions{
    TempUnit defaultTempUnity = TempUnit::CELSIUS;
    MenuScreen defaultScreen = MenuScreen::APP_MENU;
    bool defaultRotaryFlag = false;
    double defaultSetTempInCelsius = 300.0;
    uint16_t defaultMinTempInCelsius = 100;
    uint16_t defaultMaxTempInCelsius = 400;
    //todo add calibration variables
};
struct UserInput{
    bool btn1_LockFree_Back = 0;
    bool btn2_Menu_Select = 0;
    int rotaryIncrement = 0;
};

struct SolderingStationData{
public:
    double setTemperatureInCelsius;
    double mesTemperatureInCelsius;
    double pwmValueInPercent;

    uint16_t minTempInCelsius;
    uint16_t maxTempInCelsius;

    UserInput userInput;

    TempUnit tempUnity;
    MenuScreen currentScreen;
    bool rotaryEncoderLocked;
private:
    StartupOptions startupOptions;

public:
    SolderingStationData(){
        loadOptionsFromEEPROM();
        initializeMembersFromOptions();
    }
    void incrementSetTempWithinLimits(int increment){
        setTemperatureInCelsius += increment;
        if(setTemperatureInCelsius > maxTempInCelsius){
            this->setTemperatureInCelsius = maxTempInCelsius;
        }else if(setTemperatureInCelsius < minTempInCelsius){
            this->setTemperatureInCelsius = minTempInCelsius;
        }
    }
private:
    void loadOptionsFromEEPROM(){
        //todo
    }
    void storeOptionToEEPROM(){
        //todo
    }
    void initializeMembersFromOptions(){
        this->tempUnity = this->startupOptions.defaultTempUnity;
        this->currentScreen = this->startupOptions.defaultScreen;
        this->rotaryEncoderLocked = this->startupOptions.defaultRotaryFlag;
        this->setTemperatureInCelsius = this->startupOptions.defaultSetTempInCelsius;
        this->minTempInCelsius = this->startupOptions.defaultMinTempInCelsius;
        this->maxTempInCelsius = this->startupOptions.defaultMaxTempInCelsius;
    }
};

#endif //SOLDERINGSTATIONFIRMWARE_SOLDERINGSTATIONDATA_H
