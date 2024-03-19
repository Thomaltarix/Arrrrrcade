/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic
*/

#pragma once

#include "IEntity.hpp"
#include "IText.hpp"
#include "ISound.hpp"
#include <memory>

enum Keys {
    UNKNOWN = -1,
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
    F = 5,
    G = 6,
    H = 7,
    I = 8,
    J = 9,
    K = 10,
    L = 11,
    M = 12,
    N = 13,
    O = 14,
    P = 15,
    Q = 16,
    R = 17,
    S = 18,
    T = 19,
    U = 20,
    V = 21,
    W = 22,
    X = 23,
    Y = 24,
    Z = 25,
    ESCAPE = 26,
    TAB = 27,
    SHIFT = 28,
    CONTROL = 29,
    SPACE = 30,
    ENTER = 31,
    BACKSPACE = 32,
    UP = 33,
    DOWN = 34,
    LEFT = 35,
    RIGHT = 36,
    ZERO = 37,
    ONE = 38,
    TWO = 39,
    THREE = 40,
    FOUR = 41,
    FIVE = 42,
    SIX = 43,
    SEVEN = 44,
    EIGHT = 45,
    NINE = 46
};

class IGraphic {
    public:
        virtual ~IGraphic() = default;

        //Window
        virtual bool isWindowOpen() const = 0;
        virtual void closeWindow() = 0;
        virtual void clearWindow() = 0;

        //Event
        virtual int getKeyEvent() = 0;

        //Display
        virtual void displayWindow() = 0;
        virtual void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) = 0;
        virtual void displayText(std::vector<std::shared_ptr<IText>> texts) = 0;
        virtual void playSound(std::vector<std::shared_ptr<ISound>> sounds) = 0;
};
