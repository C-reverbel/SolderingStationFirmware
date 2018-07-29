#ifndef SOLDERINGSTATIONFIRMWARE_OPTIONSMENU_H
#define SOLDERINGSTATIONFIRMWARE_OPTIONSMENU_H

#include "frontend/MenuStructure/MenuItem.h"

class OptionsMenu : public MenuItem {
private:
    String option_text = "OPTS";
    uint8_t selectableOptionsIndex = 0;
    static const uint8_t nbOfOptions = 3;
    MenuScreen selectableOptionsList[nbOfOptions] = {
            MenuScreen::MIN_TEMP_OPTIONS_MENU,
            MenuScreen::MAX_TEMP_OPTIONS_MENU,
            MenuScreen::TEMP_UNIT_OPTIONS_MENU
    };
    String selectableOptionsStringsList[nbOfOptions] = {
            "MIN_T",
            "MAX_T",
            "UNIT"
    };
protected:
    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();

    void printOptionSelection(String selectedOption);
};

#endif //SOLDERINGSTATIONFIRMWARE_OPTIONSMENU_H