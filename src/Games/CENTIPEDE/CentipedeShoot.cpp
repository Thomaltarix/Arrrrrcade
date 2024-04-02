/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Centipede Shoot
*/

#include "CentipedeShoot.hpp"

#include <iostream>

Arcade::CentipedeShoot::CentipedeShoot()
{
    _isShoot = false;
    _wasShoot = false;
    _entity = std::make_unique<CentipedeShootEntity>(0, 0);
}

bool Arcade::CentipedeShoot::simulate()
{
    if (_isShoot) {
        clock_t currentTick = clock();
        if ((float)(currentTick - _lastTick) / CLOCKS_PER_SEC < 0.02)
            return false;
        
        _lastTick = clock();
        if (_entity->getPos()[1] < 9) {
            _isShoot = false;
            return true;
        }
        _entity->setPos(_entity->getPos()[0], _entity->getPos()[1] - 1);
        return true;
    }
    return false;
}

void Arcade::CentipedeShoot::setIsShoot(bool isShoot)
{
    _lastTick = clock();
    _isShoot = isShoot;
    setWasShoot(true);
}

void Arcade::CentipedeShoot::setWasShoot(bool wasShoot)
{
    _wasShoot = wasShoot;
}
