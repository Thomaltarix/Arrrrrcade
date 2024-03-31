/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic
*/

#pragma once

#include <string>
#include "AEntity.hpp"
#include "Rotation.hpp"

namespace Arcade {

    class APlayer {
        public:
            ~APlayer() = default;

            virtual void move(Rotation rotation) = 0;
            int die();

            //Setters
            void setSpeed(float speed);
            void setAlive(bool alive);

            //Getters
            float getSpeed();
            bool isAlive();

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
        protected:
            float _speed;
            bool _alive;
    };
}
