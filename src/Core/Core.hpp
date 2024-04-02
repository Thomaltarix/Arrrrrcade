/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#pragma once

#include "DLLoader.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "Menu.hpp"

namespace Arcade {
    class Core {

        private:
            DLLoader _loaderGraphic;
            DLLoader _loaderGame;
            std::unique_ptr<IGraphic> _graphicLib;
            std::unique_ptr<IGame> _gameLib;
            bool _isRunning;
            std::vector<std::string> _listGraphic;
            std::vector<std::string> _listGame;
            std::size_t _idxGame;
            std::size_t _idxGraphic;
            std::unique_ptr<Menu::Menu> _menu;

            void loadGraphic(const std::string & graphicLib);
            void loadGame(const std::string & gameLib);
            void gameLoop();
            void manageEvents();
            void createlistsLibs(const std::string & graphicLib);
            void renderDraw();
            void updateDraw();

            void commandExit();
            void commandBackMenu();
            void commandNextGame();
            void commandNextGraphic();
            void commandRestartGame();

            bool changeGameFromMenu(int code);
            void stopGame();

            void saveScore();

        public:
            Core();
            ~Core();
            void start(const std::string & graphicLib);

            class Error : public std::exception {
                public:

                    Error(const std::string& msg)
                    {
                        _msg = msg;
                    };

                    const char* what() const noexcept override
                    {
                        return _msg.c_str();
                    };

                private:
                    std::string _msg;
            };
    };
}
