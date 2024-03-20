/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml
*/

#include "ncurses.hpp"
#include <ncurses.h>

NCURSESlib::NCURSESlib(){
    _isOpen = false;
};

NCURSESlib::~NCURSESlib(){
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

//----

int NCURSESlib::getKeyEvent() {
    int touche = getch();

    return touche;
};
void NCURSESlib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities){
    
};

void NCURSESlib::displayText(std::vector<std::shared_ptr<IText>> texts){
    
};
