#ifndef SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H

#include <stdint.h>

#include "frontend/MenuStructure/MenuItem.h"
#include "utils/LCD/WString.h"

class AppMenu : public MenuItem {
public:
    void updateScreen(){
        //printSetTemp(200, TempUnit::CELSIUS);
        refreshScreenTask();
    }
protected:
    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();
private:
    void printSetTemp(double temperature, TempUnit unity);
    void printMesTemp(double temperature, TempUnit unity);
    String getTempString(double value, TempUnit unity);
};

#endif //SOLDERINGSTATIONFIRMWARE_APPLICATIONMENU_H
