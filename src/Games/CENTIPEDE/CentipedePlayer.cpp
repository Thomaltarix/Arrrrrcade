/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakePlayer
*/

#include "CentipedePlayer.hpp"
#include "Keys.hpp"

Arcade::CentipedePlayer::CentipedePlayer(size_t x, size_t y)
{
    this->setAlive(true);
    _body = this->makeShip(x, y);
}

// Arcade::SnakePlayer::~SnakePlayer()
// {
//     _bodies.clear();
// }

void Arcade::CentipedePlayer::deplace(std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> map, int key)
{
    (void) map;

    switch (key)
    {
    case UP:
        if ((getBody()->getPos()[1] - 1) - 7 > map.size() - 6)
            getBody()->setPos(getBody()->getPos()[0], getBody()->getPos()[1] - 1);
        break;
    case DOWN:
        if ((getBody()->getPos()[1] + 1) - 7 < map.size() - 1)
            getBody()->setPos(getBody()->getPos()[0], getBody()->getPos()[1] + 1);
        break;
    case LEFT:
        if ((getBody()->getPos()[0] - 1) - 2 > 0)
            getBody()->setPos(getBody()->getPos()[0] - 1, getBody()->getPos()[1]);
        break;
    case RIGHT:
        if ((getBody()->getPos()[0] + 1) - 2 < map.at(0).size() - 1)
            getBody()->setPos(getBody()->getPos()[0] + 1, getBody()->getPos()[1]);
        break;
    default:
        break;
    }
}

// void Arcade::CentipedePlayer::move(Rotation rotation)
// {
//     Rotation currentRotation = getRotationFromFloat(_body->getRotation());

//     if (rotation == getRotationFromFloat(currentRotation + 180) || rotation == getRotationFromFloat(currentRotation - 180))
//         return;
//     _body->setRotation(rotation);
// }

// int Arcade::SnakePlayer::die()
// {
//     this->setAlive(false);
//     return -1;
// }

// int Arcade::SnakePlayer::grow(std::pair<size_t, size_t> nextPos)
// {
//     std::shared_ptr<Arcade::SnakeBody> tail = std::make_shared<Arcade::SnakeBody>(
//     _bodies.at(_bodies.size() - 1).get()->getPos()[0],
//     _bodies.at(_bodies.size() - 1).get()->getPos()[1],
//     Arcade::SnakePlayer::getRotationFromFloat(_bodies.at(_bodies.size() - 1).get()->getRotation()));
//     _bodies.push_back(tail);
//     return simulate(nextPos);
// }

// int Arcade::CentipedePlayer::simulate(std::pair<size_t, size_t> nextPos)
// {
//     for (int i = _bodies.size() - 1; i > 0; i--) {
//         _bodies.at(i).get()->setPos(_bodies.at(i - 1).get()->getPos()[0], _bodies.at(i - 1).get()->getPos()[1]);
//         _bodies.at(i).get()->setRotation(_bodies.at(i - 1).get()->getRotation());
//     }
//     _bodies.at(0).get()->setPos(nextPos.first, nextPos.second);
//     return 0;
// }

std::shared_ptr<Arcade::CentipedeShip> Arcade::CentipedePlayer::makeShip(size_t x, size_t y)
{
    std::shared_ptr<Arcade::CentipedeShip> ship = std::make_shared<Arcade::CentipedeShip>(x, y);
    return ship;
}

// std::shared_ptr<Arcade::SnakeBody> Arcade::SnakePlayer::makeTail(size_t x, size_t y, Rotation rotation)
// {
//     std::shared_ptr<Arcade::SnakeBody> tail = std::make_shared<Arcade::SnakeBody>(x, y, rotation);
//     tail.get()->setChar('U');
//     tail.get()->setColor(std::make_unique<Arcade::Color>());
//     tail.get()->getColor()->setColor(159, 83, 236, 255);
//     tail.get()->setPath("assets/tail");
//     return tail;
// }

// void Arcade::SnakePlayer::setupBody(size_t x, size_t y, size_t size)
// {
//     size_t i = 1;

//     switch (getRotationFromFloat(_bodies.at(0).get()->getRotation())) {
//     case FRIGHT:
//         for (; i < size - 1; i++)
//             _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x - i, y, FRIGHT));
//         _bodies.push_back(makeTail(x - i, y, FRIGHT));
//         break;
//     case FLEFT:
//         for (; i < size - 1; i++)
//             _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x + i, y, FLEFT));
//         _bodies.push_back(makeTail(x + i, y, FLEFT));
//         break;
//     case FUP:
//         for (; i < size - 1; i++)
//             _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y + i, FUP));
//         _bodies.push_back(makeTail(x, y + i, FUP));
//         break;
//     case FDOWN:
//         for (; i < size - 1; i++)
//             _bodies.push_back(std::make_shared<Arcade::SnakeBody>(x, y - i, FDOWN));
//         _bodies.push_back(makeTail(x, y - i, FDOWN));
//         break;
//     default:
//         break;
//     }
// }

Arcade::Rotation Arcade::CentipedePlayer::getRotationFromFloat(float rotation)
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
