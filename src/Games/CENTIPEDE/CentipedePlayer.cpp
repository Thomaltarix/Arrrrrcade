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
    _shoot = std::make_shared<CentipedeShoot>();
}

bool Arcade::CentipedePlayer::moveInMap(Map map, int key)
{
    switch (key)
    {
    case UP:
        if ((getBody()->getPos()[1] - 1) - 7 > map.size() - 5)
            getBody()->setPos(getBody()->getPos()[0], getBody()->getPos()[1] - 1);
        return true;
    case DOWN:
        if ((getBody()->getPos()[1] + 1) - 7 < map.size())
            getBody()->setPos(getBody()->getPos()[0], getBody()->getPos()[1] + 1);
        return true;
    case LEFT:
        if ((getBody()->getPos()[0] - 1) - 2 > 0)
            getBody()->setPos(getBody()->getPos()[0] - 1, getBody()->getPos()[1]);
        return true;
    case RIGHT:
        if ((getBody()->getPos()[0] + 1) - 2 < map.at(0).size() - 2)
            getBody()->setPos(getBody()->getPos()[0] + 1, getBody()->getPos()[1]);
        return true;
    default:
        break;
    }
    return false;
}

std::shared_ptr<Arcade::CentipedeShip> Arcade::CentipedePlayer::makeShip(size_t x, size_t y)
{
    std::shared_ptr<Arcade::CentipedeShip> ship = std::make_shared<Arcade::CentipedeShip>(x, y);
    return ship;
}


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

bool Arcade::CentipedePlayer::isInsideCentipede(std::vector<std::shared_ptr<CentipedeEnemy>> enemies)
{
    for (auto enemy : enemies) {
        for (auto body : enemy->getBodies()) {
            if (body->getPos()[0] == _body->getPos()[0] && body->getPos()[1] == _body->getPos()[1])
                return true;
        }
    }
    return false;
}
