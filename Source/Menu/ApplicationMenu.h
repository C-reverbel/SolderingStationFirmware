//
// Created by carlos on 08/05/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H

#include <stdint.h>
#include "Menu.h"


class ApplicationMenu : public Menu {
private:
    uint16_t setTemp = 300;
    uint16_t mesTemp = 250;
    bool isLocked = false;

    enum TempUnity{
        CELSIUS,
        FAHRENHEIT
    };
    TempUnity tempUnity = CELSIUS;

public:
    // update menu variables based on rotary state
    void update();
    void refreshScreen();

private:
    void printSetTemp();
    void printMesTemp();

    char getTempUnity();
    uint16_t convertedTemp(uint16_t temp);
};


#endif //SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
