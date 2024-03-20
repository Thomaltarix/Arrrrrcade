/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses
*/

#include "ncurses.hpp"
#include <ncurses.h>

NCURSESlib::~NCURSESlib() {
    _isOpen = false;
};

NCURSESlib::NCURSESlib() {
    _isOpen = true;
    initscr();
    keypad(stdscr, TRUE);
    resizeterm(LINES, COLS);
    timeout(500);
};

bool NCURSESlib::isWindowOpen() const {
    return _isOpen;
};

void NCURSESlib::closeWindow() {
    _isOpen = false;
    endwin();
};

void NCURSESlib::clearWindow() {
    clear();
};

void NCURSESlib::displayWindow() {
    refresh();
};

int NCURSESlib::getKeyEvent() {
    int touche = getch();

    if (touche == '\033'){
        touche = getch();
    }
    if (touche == 27)
        closeWindow();
    return touche;
};

void NCURSESlib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities) {
    int char_todisp;

    for (auto &entity : entities) {
        char_todisp = entity.get()->getChar();
        mvprintw(entity.get()->getPos()[0], entity.get()->getPos()[1], reinterpret_cast<char*>(&char_todisp));
    }
};

void NCURSESlib::displayText(std::vector<std::shared_ptr<IText>> texts) {
    for (auto &text : texts) {
        mvprintw(text.get()->getPos()[0], text.get()->getPos()[1], text.get()->getText().c_str());
    }
};

void NCURSESlib::playSound(std::vector<std::shared_ptr<ISound>> sounds) {
    (void) sounds;

    return;
};
