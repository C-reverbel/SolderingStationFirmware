#ifndef SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H

#include "frontend/MenuStructure/MenuItem.h"

class SelectionMenu : public MenuItem {
private:
    static const char degree_symbol = '\337';
    String menu_text = "MENU";
    uint8_t selectableMenusIndex = 0;
    static const uint8_t nbOfSelectableMenus = 3;
    MenuScreen selectableMenusList[nbOfSelectableMenus] = {
        MenuScreen::APP_MENU,
        MenuScreen::CALIBRATION_MENU,
        MenuScreen::OPTIONS_MENU
    };
    String selectableMenusStringsList[nbOfSelectableMenus] = {
        "MAIN",
        "CAL ",
        "OPTS"
    };

private:
    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();

    void printMenuSelectin(String selectedMenu);
};

#endif //SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H
