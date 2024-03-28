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
#include "SnakeEntity.hpp"

#include <vector>
#include <memory>

namespace Arcade {
    class SnakePlayer : public APlayer {
        public:
            enum Rotation {
                UP = 0,
                RIGHT = 90,
                DOWN = 180,
                LEFT = 270
            };

            SnakePlayer(size_t x, size_t y, size_t size, Rotation rotation);
            ~SnakePlayer() = default;

            void move(Rotation rotation);
            int die();
            int grow(std::pair<int, int> pos);
            int simulate(std::pair<int, int> nextPos);

            // Setters
            void setSnakeSize(int size) { _snakeSize = size; };

            // Getters
            int getSnakeSize() { return _snakeSize; };
            std::shared_ptr<SnakeBody> getHead() { return _bodies.at(0); };
            std::vector<std::shared_ptr<SnakeBody>> getBodies() { return _bodies; };
            Rotation getRotationFromFloat(float rotation);
        private:
            int _snakeSize;
            std::vector<std::shared_ptr<SnakeBody>> _bodies;

            void setupBody(size_t x, size_t y, size_t size);
            std::shared_ptr<SnakeBody> Arcade::SnakePlayer::makeTail(size_t x, size_t y, Rotation rotation);
            std::shared_ptr<Arcade::SnakeBody> Arcade::SnakePlayer::makeHead(size_t x, size_t y, Rotation rotation);
    };
}
