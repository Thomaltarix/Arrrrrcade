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
            std::vector<std::shared_ptr<Arcade::IEntity>> _listEntities;
            void createEntityBackground();
        public:
            Menu();
            ~Menu();

            //Game
            int startGame();
            int stopGame();
            int getScore();
            int simulate();

            //Event
            void catchKeyEvent(int key);

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();
    };
}
