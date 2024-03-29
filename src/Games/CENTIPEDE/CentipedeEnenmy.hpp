/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakePlayer
*/

#pragma once

#include "APlayer.hpp"
#include "IText.hpp"
#include "ISound.hpp"
#include "CentipedeEntity.hpp"

namespace Arcade {
    class CentipedeEnemy : public APlayer {
        public:
            CentipedeEnemy(){};
            ~CentipedeEnemy() = default;

            void move(Rotation rotation) { (void) rotation; };
            // int die();

            //Setters
            // void setSpeed(float speed);
            // void setAlive(bool alive);

            //Getters
            // float getSpeed();
            // bool isAlive();

        private:
            float _speed;
            bool _alive;
    };
}