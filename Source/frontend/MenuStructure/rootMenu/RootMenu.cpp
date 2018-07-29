#include "RootMenu.h"

void RootMenu::handleUserInputTask(){
    // force the stack to be pushed
    MenuItem::_stackEvent = MenuItem::StackEvent::PUSH;
}
void RootMenu::refreshScreenTask(){
    // nothing to do here
}
void RootMenu::enteringStackTask(){
    // does not executes normally, call it on constructor
    MenuItem::_nextScreen = MenuItem::MenuScreen::APP_MENU;
    MenuItem::_stackEvent = MenuItem::StackEvent::PUSH;
}
void RootMenu::leavingStackTask(){
    // this should never arrive...
    //todo do something if it ever happen
}