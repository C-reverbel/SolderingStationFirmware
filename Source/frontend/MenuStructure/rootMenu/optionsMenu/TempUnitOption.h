#ifndef SOLDERINGSTATIONFIRMWARE_TEMPUNITOPTION_H
#define SOLDERINGSTATIONFIRMWARE_TEMPUNITOPTION_H


#include "../../MenuItem.h"
#include "../../../../utils/LCD/WString.h"

class TempUnitOption : public MenuItem{
private:
    TempUnit defaultTempUnit = TempUnit::CELSIUS;
    String unit_text = "T_UNIT";
    uint8_t selectableUnitIndex = 0;
    static const uint8_t nbOfOptions = 2;
    TempUnit selectableUnitList[nbOfOptions] = {
        TempUnit::CELSIUS,
        TempUnit::FAHRENHEIT
    };
    String selectableUnitStringsList[nbOfOptions] = {
        "CELS",
        "FAHR"
    };

private:
    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();

    void printSelectedUnit(String unit);

};


#endif //SOLDERINGSTATIONFIRMWARE_TEMPUNITOPTION_H
