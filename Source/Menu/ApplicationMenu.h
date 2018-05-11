//
// Created by carlos on 08/05/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H

#include <stdint.h>
#include "Menu.h"


class ApplicationMenu : public Menu {
private:
    uint16_t* mesTemp;
    uint16_t* setTemp;
    enum TempUnity {
        CELSIUS,
        FAHRENHEIT
    } tempUnity = CELSIUS;
    bool isLocked = false;

public:
    ApplicationMenu(uint16_t* setTemp, uint16_t* mesTemp);

    // update menu variables based on rotary state
    void update();
    void refreshScreen();

private:
    void printSetTemp(uint16_t temperature, TempUnity unity);
    void printMesTemp(uint16_t temperature, TempUnity unity);

    String getTempString(uint16_t value, TempUnity unity);

};


#endif //SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
