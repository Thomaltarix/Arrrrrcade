/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#pragma once

#include "IGame.hpp"

#define BUTTON_IDLE "src/Core/Menu/assets/button-idle"
#define BUTTON_PRESSED "src/Core/Menu/assets/button-pressed"
#define BUTTON_SELECTED "src/Core/Menu/assets/button-selected"

namespace Arcade {
    namespace Menu {
        class Menu : public virtual IGame {
            private:
                bool _isPlayPressed;
                std::vector<std::shared_ptr<Arcade::IEntity>> _listEntities;
                std::vector<std::shared_ptr<Arcade::IText>> _listText;
                std::vector<std::string> _listGraphic;
                std::vector<std::string> _listGame;

                std::string _selectedGraphic;
                std::string _selectedGame;

                std::vector<std::size_t> _cursor;

                std::string _userNameDisplay;
                std::string _userName;
                std::size_t _userNameIndex;


                void createEntityBackground();
                void createEntityPlay();
                void createLibsButtons();
                void createUserName();
                void createButton(std::size_t posx, std::size_t posy, std::size_t sizex, std::size_t sizey, std::string path);

                void createText(std::string text, std::size_t posx, std::size_t posy, std::size_t size);
                void createLibsTexts();

                void handleArrowKey(int key);
                void handleEnterKey(int key);
                void keyUp();
                void keyDown();
                void keyLeft();
                void keyRight();

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
