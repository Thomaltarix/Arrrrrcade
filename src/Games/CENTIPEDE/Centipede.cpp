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
        } else if (isInsideBox(_player->getShoot()->getShoot()->getPos())) {
            transformBox(_player->getShoot()->getShoot()->getPos());
        }
    }
    if (!_player->getShoot()->isShoot() && _player->getShoot()->wasShoot()) {
        _map[_player->getShoot()->getShoot()->getPos()[0] - 2][_player->getShoot()->getShoot()->getPos()[1] - 7] =
        std::make_shared<CentipedeVoid>(_player->getShoot()->getShoot()->getPos()[0] - 2, _player->getShoot()->getShoot()->getPos()[1] - 7);
    }
}

bool Arcade::Centipede::isInsideEnemy(std::vector<size_t> pos)
{
    for (size_t enemy = 0; enemy < _enemies.size(); enemy++) {
        for (auto body : _enemies[enemy]->getBodies()) {
            if (body.get()->getPos()[0] == pos[0] && body.get()->getPos()[1] == pos[1]) {
                _score += 1;
                cutEnemy(pos, enemy);
                return true;
            }
        }
    }
    return false;
}

void Arcade::Centipede::cutEnemy(std::vector<size_t> pos, size_t enemy) {
    int size = _enemies[enemy]->getSnakeSize();
    if (size == 2) {
        _enemies.erase(_enemies.begin() + enemy);
        return;
    }
    _enemies.push_back(std::make_shared<CentipedeEnemy>
    (_enemies[enemy]->getHead()->getPos()[0] - 2, _enemies[enemy]->getHead()->getPos()[1] - 7, size / 2,
    (_enemies[enemy]->getRotationFromFloat(_enemies[enemy]->getHead()->getRotation())), CENTIPEDE_SPEED + _nbWaves));

    if (_enemies[enemy]->getRotationFromFloat(_enemies[enemy]->getHead()->getRotation()) == FLEFT)
        _enemies.push_back(std::make_shared<CentipedeEnemy>
        (pos[0] - 2, pos[1] - 7, size / 2, FRIGHT, CENTIPEDE_SPEED + _nbWaves));
    else
        _enemies.push_back(std::make_shared<CentipedeEnemy>
        (pos[0] - 2, pos[1] - 7, size / 2, FLEFT, CENTIPEDE_SPEED + _nbWaves));

    _enemies.erase(_enemies.begin() + enemy);
}

bool Arcade::Centipede::isInsideBox(std::vector<size_t> pos)
{
    if (_map[pos[0] - 2][pos[1] - 8]->getChar() == 'X') {
        return true;
    }
    return false;
}

void Arcade::Centipede::transformBox(std::vector<size_t> pos)
{
    char a;
    std::string path = "assets/Centipede/box-";

    if (_map[pos[0] - 2][pos[1] - 8]->getPath() == "assets/Centipede/box-1")
        _map[pos[0] - 2][pos[1] - 8] = std::make_shared<CentipedeVoid>(pos[0] - 2, pos[1] - 8);
    else {
        a = _map[pos[0] - 2][pos[1] - 8]->getPath().back() - 1;
        _map[pos[0] - 2][pos[1] - 8]->setPath(path + a);
    }
    _player->getShoot()->setIsShoot(false);
}
