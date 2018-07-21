#ifndef SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H

#include <stdint.h>

#include "Menu.h"
#include "MenuModel.h"


class ApplicationMenu : public Menu {
public:
    ApplicationMenu();
    void refreshScreen(uint16_t setTemp, uint16_t mesTemp, MenuModel::TempUnity tempUnity, bool isRotaryLocked);
private:
    void printSetTemp(uint16_t temperature, MenuModel::TempUnity unity);
    void printMesTemp(uint16_t temperature, MenuModel::TempUnity unity);

    String getTempString(uint16_t value, MenuModel::TempUnity unity);
};


#endif //SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
