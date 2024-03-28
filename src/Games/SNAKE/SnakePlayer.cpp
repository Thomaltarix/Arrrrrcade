/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakePlayer
*/

#include "SnakePlayer.hpp"

Arcade::SnakePlayer::SnakePlayer(size_t x, size_t y, size_t size, Rotation rotation)
{
    this->setAlive(true);
    this->setSnakeSize(size);
    this->setSpeed(1);

    _bodies.push_back(this->makeHead(x, y, rotation));
    this->setupBody(x, y, size);
}

void Arcade::SnakePlayer::move(Rotation rotation)
{
    Rotation currentRotation = getRotationFromFloat(_bodies.at(0).get()->getRotation());

    if (rotation == getRotationFromFloat(currentRotation + 180) || rotation == getRotationFromFloat(currentRotation - 180))
        return;
    _bodies.at(0).get()->setRotation(rotation);
}

int Arcade::SnakePlayer::die()
{
    this->setAlive(false);
    _bodies.clear();
    return -1;
}

int Arcade::SnakePlayer::grow()
{
}

int Arcade::SnakePlayer::simulate()
{
    return 0;
}

std::shared_ptr<Arcade::SnakeBody> Arcade::SnakePlayer::makeHead(size_t x, size_t y, Rotation rotation)
{
    std::shared_ptr<Arcade::SnakeBody> head = std::make_shared<Arcade::SnakeBody>(x, y, rotation);
    head.get()->setChar('S');
    head.get()->setColor(std::make_unique<Arcade::Color>());
    head.get()->getColor()->setColor(128, 255, 0, 255);
    head.get()->setPath("assets/head");
    return head;
}

std::shared_ptr<Arcade::SnakeBody> Arcade::SnakePlayer::makeTail(size_t x, size_t y, Rotation rotation)
{
    std::shared_ptr<Arcade::SnakeBody> tail = std::make_shared<Arcade::SnakeBody>(x, y, rotation);
    tail.get()->setChar('U');
    tail.get()->setColor(std::make_unique<Arcade::Color>());
    tail.get()->getColor()->setColor(159, 83, 236, 255);
    tail.get()->setPath("assets/tail");
    return tail;
}

void Arcade::SnakePlayer::setupBody(size_t x, size_t y, size_t size)
{
    int i = 1;

    switch (getRotationFromFloat(_bodies.at(0).get()->getRotation())) {
    case RIGHT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x - i, y, RIGHT));
        _bodies.push_back(makeTail(x - i, y, RIGHT));
        break;
    case LEFT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x + i, y, LEFT));
        _bodies.push_back(makeTail(x + i, y, LEFT));
        break;
    case UP:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y + i, UP));
        _bodies.push_back(makeTail(x, y + i, UP));
        break;
    case DOWN:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y - i, DOWN));
        _bodies.push_back(makeTail(x, y - i, DOWN));
        break;
    default:
        break;
    }
}

Arcade::SnakePlayer::Rotation Arcade::SnakePlayer::getRotationFromFloat(float rotation)
{
    if (rotation == 0)
        return UP;
    if (rotation == 90)
        return RIGHT;
    if (rotation == 180)
        return DOWN;
    if (rotation == 270)
        return LEFT;
    return UP;
}
