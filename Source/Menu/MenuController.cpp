#include "MenuController.h"

MenuController::MenuController(MenuView* menuView, MenuModel* menuModel) {
    _menuView = menuView;
    _menuModel = menuModel;

    initVariables();
}

void MenuController::handleUserIO(){
    userIO = _menuView->getIOValues();
    // handle btn1
    // handle btn2
    // handle rotary encoder
}
void MenuController::refreshScreen() {
    _menuView->refreshScreen();
}
void MenuController::updateTemperatures(){
    // update mesTemp
    _menuModel->mesTemp = (uint16_t) _menuModel->measureTemp();
    // update setTemp
    if(!lockedRotaryFlag)
        _menuModel->setTemp += userIO.rotIncr;
    if(_menuModel->setTemp > 400)
        _menuModel->setTemp = 400;
    else if (_menuModel->setTemp < 100)
        _menuModel->setTemp = 100;
}
void MenuController::updatePWMValue(){
    _menuModel->pidIn = (double) _menuModel->mesTemp;
    _menuModel->pidSetpoint = (double) _menuModel->setTemp;
    _menuModel->myPID.Compute();
    _menuModel->_pwmOut->setPWMValue(_menuModel->pwmVal);
}

void MenuController::initVariables() {
    // update soldering station options from eeprom
    _menuModel->loadOptions();
    //initialize variables
    lockedRotaryFlag = _menuModel->options.lockedRotaryFlag;

    _menuModel->tempUnity = _menuModel->options.tempUnity;
    _menuModel->currentScreen = _menuModel->options.defaultScreen;
    _menuModel->lastScreen = _menuModel->options.defaultScreen;
    _menuModel->setTemp = _menuModel->options.defaultTemp;
}
