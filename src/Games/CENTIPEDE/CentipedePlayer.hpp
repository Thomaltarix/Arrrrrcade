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
#include "CentipedeShoot.hpp"
#include "CentipedeEnemy.hpp"

#include <vector>
#include <memory>

namespace Arcade {
    class CentipedePlayer : public APlayer {
        public:
            CentipedePlayer(size_t x, size_t y);
            ~CentipedePlayer() = default;

            void move(Rotation rotation) { (void) rotation; };
            bool deplace(Map map, int key);
            bool isInsideCentipede(std::vector<std::shared_ptr<CentipedeEnemy>> enemies);

            // Setters
            void setSnakeSize(int size) { _snakeSize = size; };

            // Getters
            int getSnakeSize() { return _snakeSize; };
            std::shared_ptr<CentipedeShip> getBody() { return _body; };
            std::shared_ptr<CentipedeShoot> getShoot() { return _shoot; };
            Rotation getRotationFromFloat(float rotation);
        private:
            int _snakeSize;
            std::shared_ptr<CentipedeShip> _body;
            std::shared_ptr<CentipedeShoot> _shoot;
            
            std::shared_ptr<Arcade::CentipedeShip> makeShip(size_t x, size_t y);
    };
}
