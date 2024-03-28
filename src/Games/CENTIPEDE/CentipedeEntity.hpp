/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Centipede Entity
*/

#pragma once

#include "AEntity.hpp"
#include "Rotation.hpp"

namespace Arcade {
    class CentipedeBackground : public AEntity {
        public:
            CentipedeBackground(std::size_t x, std::size_t y);
            ~CentipedeBackground() = default;
    };

    // class SnakeBody : public AEntity {
    //     public:
    //         SnakeBody(size_t x, size_t y, Rotation rotation);
    //         ~SnakeBody() = default;
    // };

    class CentipedeWall : public AEntity {
        public:
            CentipedeWall(std::size_t x, std::size_t y);
            ~CentipedeWall() = default;
    };

    class CentipedeVoid : public AEntity {
        public:
            CentipedeVoid(std::size_t x, std::size_t y);
            ~CentipedeVoid() = default;
    };

    // class SnakeApple : public AEntity {
    //     public:
    //         SnakeApple(size_t x, size_t y);
    //         ~SnakeApple() = default;
    // };
}