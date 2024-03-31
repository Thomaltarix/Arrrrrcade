/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** centipede
*/

#include "Centipede.hpp"
#include "CentipedeEntity.hpp"
#include "Text.hpp"
#include "Rules.hpp"

Arcade::Centipede::Centipede()
{
    _started = false;
    _key = -1;
    _score = 0;
    _nbCentipede = 0;
    _nbWaves = 0;

    _background = std::make_shared<CentipedeBackground>(0, 0);
    _texts = std::vector<std::shared_ptr<Arcade::IText>>();
}

Arcade::Centipede::~Centipede()
{
    _enemies.clear();
    _sounds.clear();
    _texts.clear();
    _entities.clear();
    _map.clear();
}

//Game
int Arcade::Centipede::startGame()
{
    _started = true;

    _generationClock = clock();
    _key = -1;
    _score = 0;

    _map.clear();
    this->initMap(MAP_WIDTH, MAP_HEIGHT);

    _player.reset();
    _player = std::make_unique<CentipedePlayer>(10, 19);
    _map[10][19] = _player->getBody();

    _nbCentipede = 1;
    _nbWaves = 1;
    _enemies.clear();
    _enemies.push_back(std::make_shared<CentipedeEnemy>(SIZE_CENTIPEDE, 1, SIZE_CENTIPEDE, Arcade::FRIGHT, CENTIPEDE_SPEED + _nbWaves));

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
    for (auto enemy : _enemies) {
        for (auto body : enemy->getBodies()) {
            _entities.push_back(body);
        }
    }
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::Centipede::getTexts()
{
    _texts.clear();
    std::string score = "Score: " + std::to_string(_score);
    std::shared_ptr<Arcade::IText> text = std::make_shared<Arcade::Text>(score, 9, 5, "assets/Centipede/SimplyMono-Bold");
    _texts.push_back(text);
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
