/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakeHead
*/

#pragma once

#include "AEntity.hpp"
#include "Rotation.hpp"

namespace Arcade {
    class SnakeBody : public AEntity {
        public:
            SnakeBody(size_t x, size_t y, Rotation rotation);
            ~SnakeBody() = default;
    };

    class SnakeWall : public AEntity {
        public:
            SnakeWall(size_t x, size_t y);
            ~SnakeWall() = default;
    };

    class SnakeVoid : public AEntity {
        public:
            SnakeVoid(size_t x, size_t y);
            ~SnakeVoid() = default;
    };

    class SnakeBackground : public AEntity {
        public:
            SnakeBackground(size_t x, size_t y);
            ~SnakeBackground() = default;
    };

    class SnakeApple : public AEntity {
        public:
            SnakeApple(size_t x, size_t y);
            ~SnakeApple() = default;
    };
}
