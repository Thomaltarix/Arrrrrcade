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
        DLLoader _loader;
        std::unique_ptr<IGraphic> _graphicLib;
        std::unique_ptr<IGame> _gameLib;

        void loadGraphic(const std::string & graphicLib);

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
