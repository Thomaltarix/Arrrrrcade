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

typedef std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> Map;

namespace Arcade {
    class CentipedeEnemy : public APlayer {
        public:
            CentipedeEnemy(size_t x, size_t y, size_t size, Rotation rotation, float speed);
            ~CentipedeEnemy();

            void move(Rotation rotation);
            int die();
            // int grow(std::pair<size_t, size_t> pos);
            int simulate(Map map);

            // Setters
            void setSnakeSize(int size) { _snakeSize = size; };

            // Getters
            int getSnakeSize() { return _snakeSize; };
            std::shared_ptr<CentipedeEnemyBody> getHead() { return _bodies.at(0); };
            std::vector<std::shared_ptr<CentipedeEnemyBody>> getBodies() { return _bodies; };
            Rotation getRotationFromFloat(float rotation);
            std::pair<size_t, size_t> getNextPost();
        private:
            clock_t _lastTick;
            Rotation _lastRotate;
            int _snakeSize;
            std::vector<std::shared_ptr<CentipedeEnemyBody>> _bodies;

            void setupBody(size_t x, size_t y, size_t size);
            std::shared_ptr<CentipedeEnemyBody> makeTail(size_t x, size_t y, Rotation rotation);
            std::shared_ptr<Arcade::CentipedeEnemyBody> makeHead(size_t x, size_t y, Rotation rotation);
            bool isInsideWall(std::pair<size_t, size_t> pos, Map map);
            void moveDown();
    };
}