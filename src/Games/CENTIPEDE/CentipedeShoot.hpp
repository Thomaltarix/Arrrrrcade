/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Centipede Shoot
*/

#pragma once

#include "CentipedeEntity.hpp"

namespace Arcade {
    class CentipedeShoot {
        public:
            CentipedeShoot();
            ~CentipedeShoot() = default;
            bool isShoot() { return _isShoot; };
            bool wasShoot() { return _wasShoot; };
            void setIsShoot(bool isShoot);
            void setWasShoot(bool wasShoot);
            std::shared_ptr<CentipedeShootEntity> getShoot() { return _entity; };
            bool simulate();

        private:
            std::shared_ptr<CentipedeShootEntity> _entity;
            bool _isShoot;
            bool _wasShoot;
            clock_t _lastTick;
    };
}
