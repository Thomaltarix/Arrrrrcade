/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses
*/

#include "ncurses.hpp"
#include <ncurses.h>

Arcade::NCURSESlib::~NCURSESlib() {
    _isOpen = false;
};

Arcade::NCURSESlib::NCURSESlib() {
    _isOpen = true;
    initscr();
    keypad(stdscr, TRUE);
    resizeterm(LINES, COLS);
    timeout(500);
};

bool Arcade::NCURSESlib::isWindowOpen() const {
    return _isOpen;
};

void Arcade::NCURSESlib::closeWindow() {
    _isOpen = false;
    endwin();
};

void Arcade::NCURSESlib::clearWindow() {
    clear();
};

void Arcade::NCURSESlib::displayWindow() {
    refresh();
};

int Arcade::NCURSESlib::getKeyEvent() {
    int touche = getch();

    if (touche == '\033')
        touche = getch();
    if (touche == 27)
        closeWindow();
    if (touche == 0)
        return touche;
    for (auto &key : _keyMap) {
        if (touche == key.first)
            return key.second;
    }
    return -1;
};

void Arcade::NCURSESlib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities) {
    int char_todisp;

    for (auto &entity : entities) {
        char_todisp = entity.get()->getChar();
        mvprintw(entity.get()->getPos()[0], entity.get()->getPos()[1], reinterpret_cast<char*>(&char_todisp));
    }
};

void Arcade::NCURSESlib::displayText(std::vector<std::shared_ptr<IText>> texts) {
    for (auto &text : texts) {
        mvprintw(text.get()->getPos()[0], text.get()->getPos()[1], text.get()->getText().c_str());
    }
};

void Arcade::NCURSESlib::playSound(std::vector<std::shared_ptr<ISound>> sounds) {
    (void) sounds;

    return;
};
