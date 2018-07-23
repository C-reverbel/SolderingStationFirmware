#include "MenuController.h"

MenuController::MenuController(MenuView* menuView, MenuModel* menuModel) {
    _menuView = menuView;
    _menuModel = menuModel;

    initVariables();
}

void MenuController::handleUserInput(){
    // update userIO members and handles btn1, btn2 and rotary encoder
    int temp = 0;
    userIO = _menuView->getIOValues();
    switch(_menuModel->currentScreen){
        case Menu::MenuScreen::APP_MENU:
            // handle buttons
            if(userIO.btn1){
                lockedRotaryFlag = !lockedRotaryFlag;
            }if(userIO.btn2){
                _menuModel->lastScreen = _menuModel->currentScreen;
                _menuModel->currentScreen = Menu::MenuScreen::SELECTION_MENU;
                _menuView->resetSelectionMenu();
            }
            // handle rotary encoder
            if(!lockedRotaryFlag){
                _menuModel->setTemp_PIDSetpoint += userIO.rotIncr;
            }if(_menuModel->setTemp_PIDSetpoint > 400){
                _menuModel->setTemp_PIDSetpoint = 400;
            } else if (_menuModel->setTemp_PIDSetpoint < 100){
                _menuModel->setTemp_PIDSetpoint = 100;
            }
        break;
        case Menu::MenuScreen::SELECTION_MENU:
            // handle buttons
            if(userIO.btn1){
                _menuModel->currentScreen = _menuModel->lastScreen;
                _menuModel->lastScreen = Menu::MenuScreen::SELECTION_MENU;
            }
            if(userIO.btn2){
                _menuModel->currentScreen = _menuView->listOfSelectableMenus[_menuView->highlightedMenuIndex];
                _menuModel->lastScreen = Menu::MenuScreen::SELECTION_MENU;
            }
            // handle rotary encoder
            if(userIO.rotIncr > 0){
                temp = _menuView->highlightedMenuIndex + 1;
                if(temp > _menuView->numberOfSelectableMenus - 1) { _menuView->highlightedMenuIndex = _menuView->numberOfSelectableMenus - 1; }
                else { _menuView->highlightedMenuIndex = temp; }
            }else if(userIO.rotIncr < 0){
                temp = _menuView->highlightedMenuIndex - 1;
                if(temp < 0) { _menuView->highlightedMenuIndex = 0; }
                else { _menuView->highlightedMenuIndex = temp; }
            }
        break;
    }

}
void MenuController::refreshScreen() {
    uint16_t setTemp = (uint16_t) _menuModel->setTemp_PIDSetpoint;
    uint16_t mesTemp = (uint16_t) _menuModel->mesTemp_PIDIn;
    String tempStr = "";
    switch(_menuModel->currentScreen){
        case Menu::MenuScreen::APP_MENU:
            _menuView->appMenu.refreshScreen(setTemp, mesTemp, _menuModel->tempUnity, lockedRotaryFlag);
        break;
        case Menu::MenuScreen::SELECTION_MENU:
            tempStr = Menu::getMenuString(_menuView->listOfSelectableMenus[_menuView->highlightedMenuIndex]);
            _menuView->selectMenu.refreshScreen(tempStr);
        break;
        case Menu::MenuScreen::OPTIONS_MENU:
            _menuView->optionsMenu.refreshScreen();
        break;
    }
}
void MenuController::updatePWMValue(){
    // update mesTemp
    _menuModel->mesTemp_PIDIn = _menuModel->measureTemp();
    _menuModel->myPID.Compute();
    _menuModel->_pwmOut->setPWMValue(_menuModel->pwmVal_PIDOut);
}

void MenuController::initVariables() {
    // update soldering station options from eeprom
    _menuModel->loadOptions();
    //initialize variables
    lockedRotaryFlag = _menuModel->options.lockedRotaryFlag;

    _menuModel->tempUnity = _menuModel->options.tempUnity;
    _menuModel->currentScreen = _menuModel->options.defaultScreen;
    _menuModel->lastScreen = _menuModel->options.defaultScreen;
    _menuModel->setTemp_PIDSetpoint = _menuModel->options.defaultTemp;
}