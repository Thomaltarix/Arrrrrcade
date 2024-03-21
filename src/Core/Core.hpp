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

class Core {

    private:
        DLLoader _loaderGraphic;
        DLLoader _loaderGame;
        std::unique_ptr<IGraphic> _graphicLib;
        std::unique_ptr<IGame> _gameLib;
        bool _isRunning;

        void loadGraphic(const std::string & graphicLib);
        void loadGame(const std::string & gameLib);
        void gameLoop();
        void manageEvents();

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
