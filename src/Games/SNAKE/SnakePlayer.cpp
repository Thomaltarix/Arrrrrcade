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

    _bodies.push_back(makeHead(x, y, rotation));
    this->setupBody(x, y, size);
}

void Arcade::SnakePlayer::move(Rotation rotation)
{
    Rotation currentRotation = (Rotation)((int)_bodies.at(0).get()->getRotation());

    if (rotation == (Rotation)(currentRotation + 180) || rotation == (Rotation)(currentRotation - 180))
        return;
    _bodies.at(0).get()->setRotation(rotation);
}

int Arcade::SnakePlayer::die()
{
    this->setAlive(false);
    _bodies.clear();
    return -1;
}

void Arcade::SnakePlayer::grow()
{
    size_t x = _bodies.at(_bodies.size() - 1).get()->getPos().x;
    size_t y = _bodies.at(_bodies.size() - 1).get()->getPos().y;
    Rotation rotation = _bodies.at(_bodies.size() - 1).get()->getRotation();

    _bodies.push_back(makeTail(x, y, rotation));
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

    switch (_bodies.at(0).get()->getRotation()) {
    case (float)RIGHT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x - i, y, RIGHT));
        _bodies.push_back(makeTail(x - i, y, RIGHT));
        break;
    case (float)LEFT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x + i, y, LEFT));
        _bodies.push_back(makeTail(x + i, y, LEFT));
        break;
    case (float)UP:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y + i, UP));
        _bodies.push_back(makeTail(x, y + i, UP));
        break;
    case (float)DOWN:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y - i, DOWN));
        _bodies.push_back(makeTail(x, y - i, DOWN));
        break;
    default:
        break;
    }
}
