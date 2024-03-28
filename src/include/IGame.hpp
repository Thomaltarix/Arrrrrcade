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

namespace Arcade {
    class IGame {
        public:
            virtual ~IGame() = default;

            //Game
            virtual int startGame() = 0;
            virtual int stopGame() = 0;
            virtual int getScore() = 0;
            virtual int simulate() = 0;

            //Event
            virtual void catchKeyEvent(int key) = 0;

            //Display
            virtual std::vector<std::shared_ptr<IEntity>> getEntities() = 0;
            virtual std::vector<std::shared_ptr<IText>> getTexts() = 0;
            virtual std::vector<std::shared_ptr<ISound>> getSounds() = 0;
    };
}
