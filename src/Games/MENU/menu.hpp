/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#pragma once

#include "IGame.hpp"

namespace Arcade {
    class Menu : public virtual IGame {
        private:
        public:
            Menu();
            ~Menu();

            //Game
            void startGame();
            void stopGame();
            int getScore();
            void simulate();

            // //Event
            void catchKeyEvent(int key);

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();
    };
}
