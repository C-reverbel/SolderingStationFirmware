#include <util/delay.h>
#include "SelectionMenu.h"

SelectionMenu::SelectionMenu() {
    this->screen = Menu::MenuScreen::SELECTION_MENU;
}

void SelectionMenu::refreshScreen(String highlightedMenu){
    _lcd->clear();
    // print first line
    _lcd->setCursor(0,0); _lcd->print(leftArrow);
    _lcd->setCursor(2,0); _lcd->print(highlightedMenu);
    _lcd->setCursor(7,0); _lcd->print(rightArrow);
    // print second line
    _lcd->setCursor(0,1); _lcd->print(leftArrow);
    _lcd->setCursor(2,1); _lcd->print(menu_text);
    _lcd->setCursor(7,1); _lcd->print(rightArrow);
}