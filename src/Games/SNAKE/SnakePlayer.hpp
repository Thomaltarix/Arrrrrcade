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
            SnakePlayer(size_t x, size_t y, size_t size, Rotation rotation);
            ~SnakePlayer();

            void move(Rotation rotation);
            int die();
            int grow(std::pair<size_t, size_t> pos);
            int simulate(std::pair<size_t, size_t> nextPos);

            // Setters
            void setSnakeSize(int size) { _snakeSize = size; };

            // Getters
            int getSnakeSize() { return _snakeSize; };
            std::shared_ptr<SnakeBody> getHead() { return _bodies.at(0); };
            std::vector<std::shared_ptr<SnakeBody>> getBodies() { return _bodies; };
            Rotation getRotationFromFloat(float rotation);
            std::pair<size_t, size_t> getNextPost();
        private:
            int _snakeSize;
            std::vector<std::shared_ptr<SnakeBody>> _bodies;

            void setupBody(size_t x, size_t y, size_t size);
            std::shared_ptr<SnakeBody> makeTail(size_t x, size_t y, Rotation rotation);
            std::shared_ptr<Arcade::SnakeBody> makeHead(size_t x, size_t y, Rotation rotation);
    };
}
