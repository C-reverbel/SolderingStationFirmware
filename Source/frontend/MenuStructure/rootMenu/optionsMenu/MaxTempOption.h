#ifndef SOLDERINGSTATIONFIRMWARE_MAXTEMPOPTION_H
#define SOLDERINGSTATIONFIRMWARE_MAXTEMPOPTION_H

#define ABSOLUTE_MAX_TEMPERATURE 450

#include "frontend/MenuStructure/MenuItem.h"

class MaxTempOption : public MenuItem{
private:
    uint16_t defaultMaxTemp;

    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();

    void printSelectedTemperature(uint16_t temperature);
    String getTempString(uint16_t value, TempUnit unity);
};


#endif //SOLDERINGSTATIONFIRMWARE_MAXTEMPOPTION_H
