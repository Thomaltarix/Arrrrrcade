/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2
*/

#pragma once

#include "AGraphic.hpp"
#include <ncurses.h>
#include <unordered_map>

class NCURSESlib : public AGraphic {

    private:
        bool _isOpen;
    const std::unordered_map<int, int> _keyMap = {
        {97, 0},    // A
        {98, 1},    // B
        {99, 2},    // C
        {100, 3},   // D
        {101, 4},   // E
        {102, 5},   // F
        {103, 6},   // G
        {104, 7},   // H
        {105, 8},   // I
        {106, 9},   // J
        {107, 10},  // K
        {108, 11},  // L
        {109, 12},  // M
        {110, 13},  // N
        {111, 14},  // O
        {112, 15},  // P
        {113, 16},  // Q
        {114, 17},  // R
        {115, 18},  // S
        {116, 19},  // T
        {117, 20},  // U
        {118, 21},  // V
        {119, 22},  // W
        {120, 23},  // X
        {121, 24},  // Y
        {122, 25},  // Z
        {27, 26},   // Escape
        {9, -1},    // Tab
        {16, -1},   // LShift
        {29, -1},   // LControl
        {' ', 30},   // Space
        {KEY_ENTER, 31},   // Enter
        {KEY_BACKSPACE, 32},  // BackSpace
        {KEY_UP, 33},  // Up
        {KEY_DOWN, 34},  // Down
        {KEY_LEFT, 35},  // Left
        {KEY_RIGHT, 36},  // Right
        {48, '0'},   // Num0
        {49, '1'},   // Num1
        {50, '2'},   // Num2
        {51, '3'},   // Num3
        {52, '4'},   // Num4
        {53, '5'},   // Num5
        {54, '6'},   // Num6
        {55, '7'},   // Num7
        {56, '8'},   // Num8
        {57, '9'}    // Num9
    };

    public:
        NCURSESlib();
        ~NCURSESlib() override;

        //Window
        bool isWindowOpen() const override;
        void closeWindow() override;
        void clearWindow() override;

        //Event
        int getKeyEvent() override;

        //Display
        void displayWindow();
        void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
        void displayText(std::vector<std::shared_ptr<IText>> texts) override;
};
