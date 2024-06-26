/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** APlayer
*/

#include "APlayer.hpp"

void Arcade::APlayer::die()
{
    this->setAlive(false);
}

void Arcade::APlayer::setSpeed(float speed)
{
    _speed = speed;
}

void Arcade::APlayer::setAlive(bool alive)
{
    _alive = alive;
}

float Arcade::APlayer::getSpeed()
{
    return _speed;
}

bool Arcade::APlayer::isAlive()
{
    return _alive;
}
