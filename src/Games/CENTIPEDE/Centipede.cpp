/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** centipede
*/

#include "Centipede.hpp"
#include "CentipedeEntity.hpp"

Arcade::Centipede::Centipede()
{
    _started = false;
    _score = 0;
    this->initMap(19, 20);
    _entities.push_back(std::make_shared<CentipedeBackground>(0, 0));
}

Arcade::Centipede::~Centipede()
{

}


//Game
int Arcade::Centipede::startGame()
{
    _started = true;
    return 0;
}

int Arcade::Centipede::stopGame()
{
    _started = false;
    return 0;
}

int Arcade::Centipede::getScore()
{
    return _score;
}

int Arcade::Centipede::simulate()
{
    return 0;
}


//Event
void Arcade::Centipede::catchKeyEvent(int key)
{
    (void) key;
}


//UserName
void Arcade::Centipede::setUserName(const std::string &name)
{
    _userName = name;
}

std::string Arcade::Centipede::getUserName()
{
    return _userName;
}


//Display
std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::Centipede::getEntities()
{
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::Centipede::getTexts()
{
    return _texts;
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::Centipede::getSounds()
{
    return _sounds;
}

void Arcade::Centipede::initMap(int width, int height)
{
    std::vector<std::shared_ptr<IEntity>> tmp;
    for (int row = 0; row < height; row++) {
        std::vector<std::shared_ptr<IEntity>> line;
        if (row == 0 || row == height - 1)
            tmp = makeVerticalSides<CentipedeWall>(width, row);
        else
            tmp = makeHorizontalSides<CentipedeWall, CentipedeVoid>(width, row);
        _map.push_back(line);
    }
}
