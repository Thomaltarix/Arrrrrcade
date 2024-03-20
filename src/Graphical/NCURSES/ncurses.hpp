/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2
*/

#pragma once

#include "AGraphic.hpp"
#include <SDL2/SDL.h>
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
        {9, 27},    // Tab
        {16, 28},   // LShift
        {29, 29},   // LControl
        {32, 30},   // Space
        {10, 31},   // Enter
        {127, 32},  // BackSpace
        {259, 33},  // Up
        {258, 34},  // Down
        {260, 35},  // Left
        {261, 36},  // Right
        {48, 37},   // Num0
        {49, 38},   // Num1
        {50, 39},   // Num2
        {51, 40},   // Num3
        {52, 41},   // Num4
        {53, 42},   // Num5
        {54, 43},   // Num6
        {55, 44},   // Num7
        {56, 45},   // Num8
        {57, 46}    // Num9
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
