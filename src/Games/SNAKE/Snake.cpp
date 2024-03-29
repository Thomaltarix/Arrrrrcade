/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakeGame
*/

#include "Snake.hpp"

Arcade::SnakeGame::SnakeGame()
{
    _started = false;
    _score = 0;
    _texts = std::vector<std::shared_ptr<Arcade::IText>>();
    this->initMap(21, 19);

    _background = std::make_shared<SnakeBackground>();
    _player = std::make_unique<SnakePlayer>(10, 9, 4, Arcade::FRIGHT);

    _lastTick = clock();
    spawnApple();

    // _texts.push_back(std::make_shared<Arcade::Text>("Score: " + std::to_string(_score), 0, 0));
}

Arcade::SnakeGame::~SnakeGame()
{
    _map.clear();
    _sounds.clear();
    _texts.clear();
    _entities.clear();
    _keyEvents.clear();
}

int Arcade::SnakeGame::startGame()
{
    // Starts the spawn of the apples and be able to move
    _started = true;
    return 0;
}

int Arcade::SnakeGame::stopGame()
{
    _started = false;
    return 0;
}

int Arcade::SnakeGame::getScore()
{
    return _score;
}

int Arcade::SnakeGame::simulate()
{
    if (!_started || !_player->isAlive())
        return -1;
    clock_t currentTick = clock();
    if ((float)(currentTick - _lastTick) / CLOCKS_PER_SEC < (1 / _player.get()->getSpeed()))
        return 0;
    _lastTick = clock();
    std::pair<int, int> nextPos = _player.get()->getNextPost();
    if (isInsideWall(nextPos))
        return _player->die();
    if (isInsideSnake(nextPos))
        return _player->die();
    if (isInsideApple(nextPos)) {
        _player->setSpeed(_player->getSpeed() + 0.2);
        _score++;
        return _player->grow(nextPos);
    }
    return _player->simulate(nextPos);
}

void Arcade::SnakeGame::catchKeyEvent(int key)
{
    for (auto &event : _keyEvents) {
        if (event.first == key)
            event.second();
    }
}

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::SnakeGame::getEntities()
{
    _entities.clear();
    _entities.push_back(_background);
    for (auto line : _map) {
        for (auto entity : line) {
            _entities.push_back(entity);
        }
    }
    for (auto body : _player->getBodies()) {
        _entities.push_back(body);
    }
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::SnakeGame::getTexts()
{
    return _texts;
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::SnakeGame::getSounds()
{
    return _sounds;
}

void Arcade::SnakeGame::initMap(int width, int height)
{
    for (int row = 0; row < height; row++) {
        std::vector<std::shared_ptr<IEntity>> line;
        if (row == 0 || row == height - 1)
            line = makeVerticalSides<SnakeWall>(width, row);
        else
            line = makeHorizontalSides<SnakeWall, SnakeVoid>(width, row);
        _map.push_back(line);
    }
}

bool Arcade::SnakeGame::isInsideWall(std::pair<size_t, size_t> pos)
{
    if (_map.at(pos.second - 10).at(pos.first - 2)->getChar() == '#') {
        return true;
    }
    return false;
}

bool Arcade::SnakeGame::isInsideSnake(std::pair<size_t, size_t> pos)
{
    for (auto body : _player->getBodies()) {
        if (body.get()->getPos()[0] == pos.first && body.get()->getPos()[1] == pos.second)
            return true;
    }
    return false;
}

bool Arcade::SnakeGame::isInsideApple(std::pair<size_t, size_t> pos)
{
    if (_map.at(pos.second - 10).at(pos.first - 2)->getChar() == '@') {
        spawnApple();
        _map.at(pos.second - 10).at(pos.first - 2) = std::make_shared<SnakeVoid>(pos.first, pos.second);
        return true;
    }
    return false;
}

void Arcade::SnakeGame::spawnApple()
{
    size_t x = rand() % _map.at(0).size() + 2;
    size_t y = rand() % _map.size() + 10;
    while (isInsideSnake(std::make_pair(x, y)) || isInsideWall(std::make_pair(x, y))) {
        x = rand() % _map.at(0).size() + 2;
        y = rand() % _map.size() + 10;
    }
    _map.at(y - 10).at(x - 2) = std::make_shared<SnakeApple>(x, y);
}
