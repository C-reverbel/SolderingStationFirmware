/*
 * - Handle user input based on current menu
 * - Update screen
 */
#ifndef SOLDERINGSTATIONFIRMWARE_FRONTEND_H
#define SOLDERINGSTATIONFIRMWARE_FRONTEND_H

#include <avr/interrupt.h>
#include <util/delay.h>
#include <frontend/MenuStructure/rootMenu/optionsMenu/MaxTempOption.h>
#include <frontend/MenuStructure/rootMenu/optionsMenu/TempUnitOption.h>

#include "frontend/MenuStructure/MenuItem.h"
#include "frontend/MenuStructure/rootMenu/RootMenu.h"
#include "frontend/MenuStructure/rootMenu/appMenu/AppMenu.h"
#include "frontend/MenuStructure/rootMenu/selectionMenu/SelectionMenu.h"
#include "frontend/MenuStructure/rootMenu/optionsMenu/OptionsMenu.h"
#include "frontend/MenuStructure/rootMenu/optionsMenu/MinTempOption.h"

#include "frontend/USER_IO/RotaryEncoder.h"
#include "frontend/USER_IO/Button.h"
#include "SolderingStationData.h"
#include "utils/LCD/LCD.h"


class Frontend {
private:
    SolderingStationData* _solderingStationData;
    LiquidCrystal* _lcd;
    // application menus
    RootMenu rootMenu;
    AppMenu appMenu;
    SelectionMenu selectionMenu;
    OptionsMenu optionsMenu;
    MinTempOption minTempOption;
    MaxTempOption maxTempOption;
    TempUnitOption tempUnitOption;

public:
    static Button* _btn1_LockFree_Back;
    static Button* _btn2_Menu_Select;
    RotaryEncoder* _rotaryEncoder;
    static bool btn1State;
    static bool btn2State;
public:
    static uint8_t menuStackIndex;
    MenuItem* menuStack[4];

private:
    void pop();
    void push(MenuItem* menu);
    void handleStack(MenuItem::StackEvent event);
    MenuItem* getMenuFromLabel(MenuItem::MenuScreen menuLabel);
public:
    Frontend( SolderingStationData* solderingStationData,
              LiquidCrystal* lcd,
              Button* btn1,
              Button* btn2,
              RotaryEncoder* rotaryEncoder);
    void updateUserInputs();
    void updateMenu();
    static void attachButtons(Button* btn1, Button* btn2);
};

#endif //SOLDERINGSTATIONFIRMWARE_FRONTEND_H