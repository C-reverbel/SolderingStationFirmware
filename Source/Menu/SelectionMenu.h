#ifndef SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H

#include "Menu.h"

class SelectionMenu : public Menu {
public:
    SelectionMenu();

    Menu::MenuScreen updateFromBtns() override;
    void refreshScreen() override;

    static void setOldMenu(Menu::MenuScreen* oldMenu);

private:
    static Menu::MenuScreen *_oldMenu;

    Menu::MenuScreen _nextMenu;

    const char leftArrow = '<';
    const char rightArrow = '>';

    const String app_menu_selection  = "MAIN";
    const String cal_menu_selection  = "CAL ";
    const String opts_menu_selection = "OPTS";
    const String menu_text = "MENU";
};


#endif //SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H
