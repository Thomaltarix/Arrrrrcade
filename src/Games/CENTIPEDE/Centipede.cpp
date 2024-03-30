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
    _key = -1;
    _started = false;
    _score = 0;
    _background = std::make_shared<CentipedeBackground>(0, 0);
}

Arcade::Centipede::~Centipede()
{

}


//Game
int Arcade::Centipede::startGame()
{
    _started = true;
    _key = -1;
    _score = 0;
    _player.reset();
    _map.clear();
    this->initMap(21, 22);
    _player = std::make_unique<CentipedePlayer>(10, 19);
    _map[10][19] = _player->getBody();


    _enemy = std::make_unique<CentipedeEnemy>(7, 1, 7, Arcade::FRIGHT);

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
    _player->deplace(_map, _key);
    simulateShoot();
    _enemy->simulate(_map);
    _map[_player->getBody()->getPos()[0] - 2][_player->getBody()->getPos()[1] - 7] = _player->getBody();
    return 0;
}


//Event
void Arcade::Centipede::catchKeyEvent(int key)
{
    _key = key;
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
    for (auto body : _enemy->getBodies()) {
        _entities.push_back(body);
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
    for (int i = 0; i < width; i ++) {
        std::vector<std::shared_ptr<IEntity>> line;
        for (int j = 0; j < height; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
                line.push_back(std::make_shared<CentipedeWall>(i,j));
            else
                line.push_back(std::make_shared<CentipedeVoid>(i,j));
        }
        _map.push_back(line);   
    }
}

void Arcade::Centipede::simulateShoot()
{
    if (_key == SPACE && !_player->getShoot()->isShoot()) {
        _map[_player->getBody()->getPos()[0] - 2][_player->getBody()->getPos()[1] - 8] = _player->getShoot()->getShoot();
        _player->getShoot()->getShoot()->setPos(_player->getBody()->getPos()[0], _player->getBody()->getPos()[1] - 1);
        _player->getShoot()->setIsShoot(true);
    }
    if (_player->getShoot()->simulate()) {
        _map[_player->getShoot()->getShoot()->getPos()[0] - 2][_player->getShoot()->getShoot()->getPos()[1] - 7] = _player->getShoot()->getShoot();
        _map[_player->getShoot()->getShoot()->getPos()[0] - 2][_player->getShoot()->getShoot()->getPos()[1] - 6] =
        std::make_shared<CentipedeVoid>(_player->getShoot()->getShoot()->getPos()[0] - 2, _player->getShoot()->getShoot()->getPos()[1] - 6);
        if (isInsideEnemy(_player->getShoot()->getShoot()->getPos())) {
            _map[_player->getShoot()->getShoot()->getPos()[0] - 2][_player->getShoot()->getShoot()->getPos()[1] - 7] =
            std::make_shared<CentipedeBox>(_player->getShoot()->getShoot()->getPos()[0] - 2, _player->getShoot()->getShoot()->getPos()[1] - 7);
            _player->getShoot()->setIsShoot(false);
            _player->getShoot()->setWasShoot(false);
        }
    }
    if (!_player->getShoot()->isShoot() && _player->getShoot()->wasShoot()) {
        _map[_player->getShoot()->getShoot()->getPos()[0] - 2][_player->getShoot()->getShoot()->getPos()[1] - 7] =
        std::make_shared<CentipedeVoid>(_player->getShoot()->getShoot()->getPos()[0] - 2, _player->getShoot()->getShoot()->getPos()[1] - 7);
    }
}

bool Arcade::Centipede::isInsideEnemy(std::vector<size_t> pos)
{
    for (auto body : _enemy->getBodies()) {
        if (body.get()->getPos()[0] == pos[0] && body.get()->getPos()[1] == pos[1])
            return true;
    }
    return false;
}
