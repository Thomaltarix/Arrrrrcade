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

typedef std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> Map;

#include <vector>
#include <memory>

namespace Arcade {
    class CentipedePlayer : public APlayer {
        public:
            CentipedePlayer(size_t x, size_t y);
            // ~SnakePlayer();

            void move(Rotation rotation) { (void) rotation; };
            bool deplace(Map map, int key);
            // int die();
            // int grow(std::pair<size_t, size_t> pos);
            int simulate();

            // Setters
            void setSnakeSize(int size) { _snakeSize = size; };

            // Getters
            int getSnakeSize() { return _snakeSize; };
            // std::shared_ptr<SnakeBody> getHead() { return _bodies.at(0); };
            std::shared_ptr<CentipedeShip> getBody() { return _body; };
            std::shared_ptr<CentipedeShoot> getShoot() { return _shoot; };
            Rotation getRotationFromFloat(float rotation);
        private:
            int _snakeSize;
            std::shared_ptr<CentipedeShip> _body;
            std::shared_ptr<CentipedeShoot> _shoot;
            

            // void setupBody(size_t x, size_t y, size_t size);
            // std::shared_ptr<SnakeBody> makeTail(size_t x, size_t y, Rotation rotation);
            std::shared_ptr<Arcade::CentipedeShip> makeShip(size_t x, size_t y);
    };
}
