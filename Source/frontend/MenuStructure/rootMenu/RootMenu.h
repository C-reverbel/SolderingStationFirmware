#ifndef SOLDERINGSTATIONFIRMWARE_ROOTMENU_H
#define SOLDERINGSTATIONFIRMWARE_ROOTMENU_H


#include "frontend/MenuStructure/MenuItem.h"

class RootMenu : public MenuItem {
public:

protected:
    void handleUserInputTask();
    void refreshScreenTask();
    void enteringStackTask();
    void leavingStackTask();
};

#endif //SOLDERINGSTATIONFIRMWARE_ROOTMENU_H