#ifndef SOLDERINGSTATIONFIRMWARE_MINTEMPOPTION_H
#define SOLDERINGSTATIONFIRMWARE_MINTEMPOPTION_H

#include "frontend/MenuStructure/MenuItem.h"

class MinTempOption : public MenuItem{
private:
    uint16_t defaultMinTemp;

    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();

    void printSelectedTemperature(uint16_t temperature);
    String getTempString(uint16_t value, TempUnit unity);
};

#endif //SOLDERINGSTATIONFIRMWARE_MINTEMPOPTION_H