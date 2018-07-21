#ifndef SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H
#define SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H

#include "Menu.h"

class SelectionMenu : public Menu {
public:
    SelectionMenu();

    void refreshScreen(String highlightedMenu);
};


#endif //SOLDERINGSTATIONFIRMWARE_SELECTIONMENU_H
