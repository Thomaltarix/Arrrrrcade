/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic
*/

#pragma once

#include "IGame.hpp"
#include <memory>

namespace Arcade {
class AGame : public IGame {
        public:
            virtual ~AGame() = default;

            //Game
            virtual int startGame() = 0;
            virtual int stopGame() = 0;
            virtual int getScore() = 0;
            virtual int simulate() = 0;

            //Event
            virtual void catchKeyEvent(int key) = 0;

            //UserName
            virtual void setUserName(const std::string &name) = 0;
            virtual std::string getUserName() = 0;

            //Display
            virtual std::vector<std::shared_ptr<IEntity>> getEntities() = 0;
            virtual std::vector<std::shared_ptr<IText>> getTexts() = 0;
            virtual std::vector<std::shared_ptr<ISound>> getSounds() = 0;

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
