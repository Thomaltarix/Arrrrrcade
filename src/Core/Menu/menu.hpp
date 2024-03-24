/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#pragma once

#include "IGame.hpp"

namespace Arcade {
    namespace Menu {
        class Menu : public virtual IGame {
            private:
                std::vector<std::shared_ptr<Arcade::IEntity>> _listEntities;
                std::vector<std::shared_ptr<Arcade::IText>> _listText;
                std::vector<std::string> _listGraphic;
                std::vector<std::string> _listGame;

                std::string _userName;
                std::size_t _userNameIndex;

                void createEntityBackground();
                void createEntityPlay();
                void createLibsButtons();
                void createUserName();
                void createButton(std::size_t posx, std::size_t posy, std::size_t sizex, std::size_t sizey);

                void createText(std::string text, std::size_t posx, std::size_t posy, std::size_t size);

            public:
                Menu(std::vector<std::string> listGraphic, std::vector<std::string> listGame);
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
}
