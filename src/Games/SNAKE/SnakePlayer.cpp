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
    this->setSpeed(5);

    _bodies.push_back(this->makeHead(x, y, rotation));
    this->setupBody(x, y, size);
}

Arcade::SnakePlayer::~SnakePlayer()
{
    _bodies.clear();
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
    return -1;
}

int Arcade::SnakePlayer::grow(std::pair<size_t, size_t> nextPos)
{
    std::shared_ptr<Arcade::SnakeBody> tail = std::make_shared<Arcade::SnakeBody>(
    _bodies.at(_bodies.size() - 1).get()->getPos()[0],
    _bodies.at(_bodies.size() - 1).get()->getPos()[1],
    Arcade::SnakePlayer::getRotationFromFloat(_bodies.at(_bodies.size() - 1).get()->getRotation()));
    _bodies.push_back(tail);
    return simulate(nextPos);
}

int Arcade::SnakePlayer::simulate(std::pair<size_t, size_t> nextPos)
{
    for (int i = _bodies.size() - 1; i > 0; i--) {
        _bodies.at(i).get()->setPos(_bodies.at(i - 1).get()->getPos()[0], _bodies.at(i - 1).get()->getPos()[1]);
        _bodies.at(i).get()->setRotation(_bodies.at(i - 1).get()->getRotation());
    }
    _bodies.at(0).get()->setPos(nextPos.first, nextPos.second);
    return 0;
}

Arcade::Rotation Arcade::SnakePlayer::getRotationFromFloat(float rotation)
{
    if (rotation == 0)
        return FUP;
    if (rotation == 90)
        return FRIGHT;
    if (rotation == 180)
        return FDOWN;
    if (rotation == 270)
        return FLEFT;
    return FUP;
}

std::pair<size_t, size_t> Arcade::SnakePlayer::getNextPost()
{
    std::vector<size_t> nextPos = this->getHead()->getPos();

    switch ((Arcade::Rotation)this->getHead()->getRotation()) {
    case Arcade::Rotation::FUP:
        nextPos[1]--;
        break;
    case Arcade::Rotation::FRIGHT:
        nextPos[0]++;
        break;
    case Arcade::Rotation::FDOWN:
        nextPos[1]++;
        break;
    case Arcade::Rotation::FLEFT:
        nextPos[0]--;
        break;
    }
    return std::make_pair(nextPos[0], nextPos[1]);
}

std::shared_ptr<Arcade::SnakeBody> Arcade::SnakePlayer::makeHead(size_t x, size_t y, Rotation rotation)
{
    std::shared_ptr<Arcade::SnakeBody> head = std::make_shared<Arcade::SnakeBody>(x, y, rotation);
    head.get()->setChar('S');
    head.get()->setColor(std::make_unique<Arcade::Color>());
    head.get()->getColor()->setColor(128, 255, 0, 255);
    head.get()->setPath("assets/Snake/head");
    return head;
}

std::shared_ptr<Arcade::SnakeBody> Arcade::SnakePlayer::makeTail(size_t x, size_t y, Rotation rotation)
{
    std::shared_ptr<Arcade::SnakeBody> tail = std::make_shared<Arcade::SnakeBody>(x, y, rotation);
    tail.get()->setChar('U');
    tail.get()->setColor(std::make_unique<Arcade::Color>());
    tail.get()->getColor()->setColor(159, 83, 236, 255);
    tail.get()->setPath("assets/Snake/tail");
    return tail;
}

void Arcade::SnakePlayer::setupBody(size_t x, size_t y, size_t size)
{
    size_t i = 1;

    switch (getRotationFromFloat(_bodies.at(0).get()->getRotation())) {
    case FRIGHT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x - i, y, FRIGHT));
        _bodies.push_back(makeTail(x - i, y, FRIGHT));
        break;
    case FLEFT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x + i, y, FLEFT));
        _bodies.push_back(makeTail(x + i, y, FLEFT));
        break;
    case FUP:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y + i, FUP));
        _bodies.push_back(makeTail(x, y + i, FUP));
        break;
    case FDOWN:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y - i, FDOWN));
        _bodies.push_back(makeTail(x, y - i, FDOWN));
        break;
    default:
        break;
    }
}
