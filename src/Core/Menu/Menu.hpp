/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#pragma once

#include "IGame.hpp"

#define BUTTON_IDLE "assets/menu/button-idle"
#define BUTTON_PRESSED "assets/menu/button-pressed"
#define BUTTON_SELECTED "assets/menu/button-selected"

namespace Arcade {
    namespace Menu {
        class Menu : public virtual IGame {
            private:
                bool _isPlayPressed;
                std::vector<std::shared_ptr<Arcade::IEntity>> _listEntities;
                std::vector<std::shared_ptr<Arcade::IText>> _listText;
                std::vector<std::string> _listGraphic;
                std::vector<std::string> _listGame;

                //current libs selected
                std::string _selectedGraphic;
                std::string _selectedGame;

                //position cursor
                std::vector<std::size_t> _cursor;

                //username
                std::string _userNameDisplay;
                std::string _userName;
                std::size_t _userNameIndex;

                //create entity
                void createEntityBackground();
                void createEntityPlay();
                void createLibsButtons();
                void createUserName();
                void createButton(std::size_t posx, std::size_t posy, std::size_t sizex, std::size_t sizey, std::string path);

                //create texts
                void createText(std::string text, std::size_t posx, std::size_t posy, std::size_t size);
                void createLibsTexts();

                //key events
                void handleArrowKey(int key);
                void handleEnterKey(int key);
                void keyUp();
                void keyDown();
                void keyLeft();
                void keyRight();

                //buttons states
                void changeButtonState(std::string path);

            public:
                Menu(std::vector<std::string> listGraphic, std::vector<std::string> listGame, std::string selectedGraphic);
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
