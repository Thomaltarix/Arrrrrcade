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

class IGame {
    public:
        virtual ~IGame() = default;

        //Game
        virtual void startGame() = 0;
        virtual void stopGame() = 0;
        virtual int getScore() = 0;
        virtual void simulate() = 0;

        //Event
        virtual void catchKeyEvent(int key) = 0;

        //Display
        virtual std::vector<std::shared_ptr<IEntity>> getEntities() = 0;
        virtual std::vector<std::shared_ptr<IText>> getTexts() = 0;
        virtual std::vector<std::shared_ptr<ISound>> getSounds() = 0;
};
