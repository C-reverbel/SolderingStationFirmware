#ifndef SOLDERINGSTATIONFIRMWARE_MENU_H
#define SOLDERINGSTATIONFIRMWARE_MENU_H

#include <avr/io.h>

#include "utils/LCD/LCD.h"
#include "SolderingStationData.h"

class MenuItem {
public:
    static enum StackEvent{
        NOTHING,
        PUSH,
        POP
    } _stackEvent;
    static enum MenuScreen{
        NULL_MENU,
        SELECTION_MENU,
        APP_MENU,
        OPTIONS_MENU,
        MIN_TEMP_OPTIONS_MENU,
        MAX_TEMP_OPTIONS_MENU,
        TEMP_UNIT_OPTIONS_MENU,
        CALIBRATION_MENU
    } _nextScreen;
protected:
    static const char degree_symbol = '\337'; // doesn't work if not static
    static SolderingStationData* _solderingStationData;
    static LiquidCrystal* _lcd;

public:
    static void attachSolderingStationData(SolderingStationData* data);
    static void attachLCD(LiquidCrystal* lcd);
    void enteringStack();
    void leavingStack();
    StackEvent update();
protected:
    virtual void handleUserInputTask();
    virtual void refreshScreenTask();
    virtual void enteringStackTask();
    virtual void leavingStackTask();
};

#endif //SOLDERINGSTATIONFIRMWARE_MENU_H