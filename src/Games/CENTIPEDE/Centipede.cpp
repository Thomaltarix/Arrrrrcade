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
    this->initMap(21, 22);
    _background = std::make_shared<CentipedeBackground>(0, 0);
    _player = std::make_unique<CentipedePlayer>(10, 18);
    _entities.push_back(_player->getBody());
    _map[10][18] = std::move(_player->getBody());
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
    for (auto &event : _keyEvents) {
        if (event.first == key)
            event.second();
    }
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
    _entities.clear();
    _entities.push_back(_background);
    for (auto line : _map) {
        for (auto entity : line) {
            _entities.push_back(entity);
        }
    }
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
    for (int row = 0; row < height; row++) {
        std::vector<std::shared_ptr<IEntity>> line;
        if (row == 0 || row == height - 1)
            line = makeVerticalSides<CentipedeWall>(width, row);
        else
            line = makeHorizontalSides<CentipedeWall, CentipedeVoid>(width, row);
        _map.push_back(line);
    }
}

std::pair<size_t, size_t> Arcade::Centipede::getNextPost()
{
    std::vector<size_t> nextPos = _player->getBody()->getPos();

    switch ((Arcade::Rotation)_player->getBody()->getRotation()) {
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
