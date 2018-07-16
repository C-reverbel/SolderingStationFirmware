#include <util/delay.h>
#include "SelectionMenu.h"

Menu::MenuScreen* SelectionMenu::_oldMenu;

SelectionMenu::SelectionMenu() {
    _nextMenu = *_oldMenu;
    this->screen = Menu::MenuScreen::SELECTION_MENU;
}

Menu::MenuScreen SelectionMenu::updateFromBtns(){
    // get buttons input and compute what to do with it
    if(*_btn1){         // return to parent menu
        _delay_us(500);
        return *_oldMenu;
    }else if(*_btn2){   // goto selected menu
        _delay_us(500);
        *_btn2 = false;
        return _nextMenu;
    }

    //todo use rotary enc. to compute next screen
    return MenuScreen::SELECTION_MENU;
}
void SelectionMenu::refreshScreen(){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); _lcd->print(leftArrow);
    _lcd->setCursor(2,0); _lcd->print(app_menu_selection);
    _lcd->setCursor(7,0); _lcd->print(rightArrow);
    // print second line
    _lcd->setCursor(0,1); _lcd->print(leftArrow);
    _lcd->setCursor(2,1); _lcd->print(menu_text);
    _lcd->setCursor(7,1); _lcd->print(rightArrow);
}

void SelectionMenu::setOldMenu(Menu::MenuScreen* oldMenu) {
    _oldMenu = oldMenu;
}