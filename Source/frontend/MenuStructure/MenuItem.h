#ifndef SOLDERINGSTATIONFIRMWARE_MENU_H
#define SOLDERINGSTATIONFIRMWARE_MENU_H

#include <avr/io.h>
#include "SolderingStationData.h"

class MenuItem {
protected:
    static uint8_t stackIndex;
    static MenuItem* menuStack[4];
    static SolderingStationData* _solderingStationData;

public:
    void update();
protected:
    void pop();
    void push(MenuItem* menu);
    static void attachSolderingStationData(SolderingStationData* data);
protected:
    virtual void enteringStack();
    virtual void leavingStack();
    virtual void handleUserInput();
    virtual void refreshScreen();
};

#endif //SOLDERINGSTATIONFIRMWARE_MENU_H
