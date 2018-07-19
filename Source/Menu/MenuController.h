#ifndef SOLDERINGSTATIONFIRMWARE_MENUCONTROLLER_H
#define SOLDERINGSTATIONFIRMWARE_MENUCONTROLLER_H

#include "MenuView.h"
#include "MenuModel.h"

class MenuController {
public:
    MenuView* _menuView;
    MenuModel* _menuModel;

    Menu::userIO userIO;

    bool lockedRotaryFlag;

public:
    MenuController(MenuView* menuView, MenuModel* menuModel);
    // handles the View
    void handleUserIO();
    void refreshScreen();
    // handles the Model
    void updateTemperatures();
    void updatePWMValue();
private:
    void initVariables();
};


#endif //SOLDERINGSTATIONFIRMWARE_MENUCONTROLLER_H
