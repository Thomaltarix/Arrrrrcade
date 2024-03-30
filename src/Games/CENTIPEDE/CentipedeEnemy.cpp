/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** CentipedeEnemy
*/

#include "CentipedeEnemy.hpp"

Arcade::CentipedeEnemy::CentipedeEnemy(size_t x, size_t y, size_t size, Rotation rotation)
{
    this->setAlive(true);
    this->setSnakeSize(size);
    this->setSpeed(5);

    _bodies.push_back(this->makeHead(x, y, rotation));
    this->setupBody(x, y, size);
    _lastTick = clock();
    _lastRotate = rotation;
}

Arcade::CentipedeEnemy::~CentipedeEnemy()
{
    _bodies.clear();
}

void Arcade::CentipedeEnemy::move(Rotation rotation)
{
    Arcade::Rotation currentRotation = getRotationFromFloat(_bodies.at(0).get()->getRotation());
    _bodies.at(0).get()->setRotation((float)rotation);
    std::pair<size_t, size_t> nextPos = this->getNextPost();

    if (_bodies.at(1).get()->getPos()[0] == nextPos.first && _bodies.at(1).get()->getPos()[1] == nextPos.second) {
        _bodies.at(0).get()->setRotation((float)currentRotation);
        return;
    }
}

int Arcade::CentipedeEnemy::die()
{
    this->setAlive(false);
    return -1;
}

int Arcade::CentipedeEnemy::simulate(Map map)
{
    clock_t currentTick = clock();
    if ((float)(currentTick - _lastTick) / CLOCKS_PER_SEC < (1 / getSpeed()))
        return 0;
    _lastTick = clock();

    moveDown();

    std::pair<size_t, size_t> nextPos = getNextPost();
    if (isInsideWall(nextPos, map)) {
        move(FDOWN);
        nextPos = getNextPost();
    }

    for (int i = _bodies.size() - 1; i > 0; i--) {
        _bodies.at(i).get()->setPos(_bodies.at(i - 1).get()->getPos()[0], _bodies.at(i - 1).get()->getPos()[1]);
        _bodies.at(i).get()->setRotation(_bodies.at(i - 1).get()->getRotation());
    }
    _bodies.at(0).get()->setPos(nextPos.first, nextPos.second);
    return 0;
}

Arcade::Rotation Arcade::CentipedeEnemy::getRotationFromFloat(float rotation)
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

std::pair<size_t, size_t> Arcade::CentipedeEnemy::getNextPost()
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

std::shared_ptr<Arcade::CentipedeEnemyBody> Arcade::CentipedeEnemy::makeHead(size_t x, size_t y, Rotation rotation)
{
    std::shared_ptr<Arcade::CentipedeEnemyBody> head = std::make_shared<Arcade::CentipedeEnemyBody>(x, y, rotation);
    head.get()->setChar('S');
    head.get()->setColor(std::make_unique<Arcade::Color>());
    head.get()->getColor()->setColor(128, 255, 0, 255);
    head.get()->setPath("assets/Centipede/head");
    return head;
}

std::shared_ptr<Arcade::CentipedeEnemyBody> Arcade::CentipedeEnemy::makeTail(size_t x, size_t y, Rotation rotation)
{
    std::shared_ptr<Arcade::CentipedeEnemyBody> tail = std::make_shared<Arcade::CentipedeEnemyBody>(x, y, rotation);
    tail.get()->setChar('U');
    tail.get()->setColor(std::make_unique<Arcade::Color>());
    tail.get()->getColor()->setColor(159, 83, 236, 255);
    tail.get()->setPath("assets/Centipede/tail");
    return tail;
}

void Arcade::CentipedeEnemy::setupBody(size_t x, size_t y, size_t size)
{
    size_t i = 1;

    switch (getRotationFromFloat(_bodies.at(0).get()->getRotation())) {
    case FRIGHT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::CentipedeEnemyBody>(x - i, y, FRIGHT));
        _bodies.push_back(makeTail(x - i, y, FRIGHT));
        break;
    case FLEFT:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::CentipedeEnemyBody>(x + i, y, FLEFT));
        _bodies.push_back(makeTail(x + i, y, FLEFT));
        break;
    case FUP:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::CentipedeEnemyBody>(x, y + i, FUP));
        _bodies.push_back(makeTail(x, y + i, FUP));
        break;
    case FDOWN:
        for (; i < size - 1; i++)
            _bodies.push_back(std::make_shared<Arcade::CentipedeEnemyBody>(x, y - i, FDOWN));
        _bodies.push_back(makeTail(x, y - i, FDOWN));
        break;
    default:
        break;
    }
}

bool Arcade::CentipedeEnemy::isInsideWall(std::pair<size_t, size_t> pos, Map map)
{
    if (map[pos.first - 2][pos.second - 7]->getChar() == '#' || map[pos.first - 2][pos.second - 7]->getChar() == 'X') {
        return true;
    }
    return false;
}

void Arcade::CentipedeEnemy::moveDown()
{
    if (getRotationFromFloat(this->getHead()->getRotation()) == FDOWN && _lastRotate == FLEFT) {
        _lastRotate = FRIGHT;
        move(FRIGHT);
    }
    if (getRotationFromFloat(this->getHead()->getRotation()) == FDOWN && _lastRotate == FRIGHT) {
        _lastRotate = FLEFT;
        move(FLEFT);
    }
}
