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

    class CentipedeShip : public AEntity {
        public:
            CentipedeShip(size_t x, size_t y);
            ~CentipedeShip() = default;
    };

    class CentipedeEnemyHead : public AEntity {
        public:
            CentipedeEnemyHead(size_t x, size_t y, Rotation rotation);
            ~CentipedeEnemyHead() = default;
    };

    class CentipedeEnemyTail : public AEntity {
        public:
            CentipedeEnemyTail(size_t x, size_t y, Rotation rotation);
            ~CentipedeEnemyTail() = default;
    };

    class CentipedeEnemyBody : public AEntity {
        public:
            CentipedeEnemyBody(size_t x, size_t y, Rotation rotation);
            ~CentipedeEnemyBody() = default;
    };

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

    class CentipedeBox : public AEntity {
        public:
            CentipedeBox(size_t x, size_t y);
            ~CentipedeBox() = default;
    };

    class CentipedeShootEntity : public AEntity {
        public:
            CentipedeShootEntity(size_t x, size_t y);
            ~CentipedeShootEntity() = default;
    };
}