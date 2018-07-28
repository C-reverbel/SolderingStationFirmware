/*
 * - Handle user input based on current menu
 * - Update screen
 */
#ifndef SOLDERINGSTATIONFIRMWARE_FRONTEND_H
#define SOLDERINGSTATIONFIRMWARE_FRONTEND_H

#include "SolderingStationData.h"
#include "utils/LCD/LCD.h"

class Frontend {
private:
    SolderingStationData& _solderingStationData;
    LiquidCrystal& _lcd;
private:


private:

public:
    Frontend(SolderingStationData& solderingStationData, LiquidCrystal& lcd);


};

#endif //SOLDERINGSTATIONFIRMWARE_FRONTEND_H
