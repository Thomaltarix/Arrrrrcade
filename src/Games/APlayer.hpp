/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic
*/

#pragma once

#include <string>
#include "AEntity.hpp"

namespace Arcade {

    class APlayer {
        public:
            ~APlayer() = default;

            virtual void move(int, int) = 0;
            virtual int die() = 0;

            //Setters
            void setSpeed(float speed) { _speed = speed; };
            void setAlive(bool alive) { _alive = alive; };

            //Getters
            float getSpeed() { return _speed; };
            bool isAlive() { return _alive; };

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
        private:
            float _speed;
            bool _alive;
    };
}
