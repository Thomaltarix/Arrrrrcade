/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses
*/

#pragma once

#include "AGraphic.hpp"
#include <ncurses.h>
#include <unordered_map>

namespace Arcade {
    class NCURSESlib : public AGraphic {

        private:
            bool _isOpen;
            const std::unordered_map<int, int> _keyMap = {
                    {'a', 0},
                    {'b', 1},
                    {'c', 2},
                    {'d', 3},
                    {'e', 4},
                    {'f', 5},
                    {'g', 6},
                    {'h', 7},
                    {'i', 8},
                    {'j', 9},
                    {'k', 10},
                    {'l', 11},
                    {'m', 12},
                    {'n', 13},
                    {'o', 14},
                    {'p', 15},
                    {'q', 16},
                    {'r', 17},
                    {'s', 18},
                    {'t', 19},
                    {'u', 20},
                    {'v', 21},
                    {'w', 22},
                    {'x', 23},
                    {'y', 24},
                    {'z', 25},
                    {27, 26},
                    {9, 27},
                    // {sf::Keyboard::LShift, 28},
                    // {sf::Keyboard::LControl, 29},
                    {' ', 30},
                    {10, 31},
                    {KEY_BACKSPACE, 32},
                    {KEY_UP, 33},
                    {KEY_DOWN, 34},
                    {KEY_LEFT, 35},
                    {KEY_RIGHT, 36},
                    {'0', 37},
                    {'1', 38},
                    {'2', 39},
                    {'3', 40},
                    {'4', 41},
                    {'5', 42},
                    {'6', 43},
                    {'7', 44},
                    {'8', 45},
                    {'9', 46}
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
            void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
    };
}
