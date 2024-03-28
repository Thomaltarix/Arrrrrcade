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
    this->initMap(19, 17);

    _player = std::make_shared<SnakePlayer>(10, 9, 4, SnakePlayer::RIGHT);

    for (auto body : _player->getBodies())
        _map.at(body->getPos()[1]).at(body->getPos()[0]) = body;
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

int Arcade::SnakeGame::simulate()
{
    if (!_started || !_player->isAlive())
        return -1;

    std::pair<int, int> nextPos = getNextPost(_player);
    if (isInsideWall(nextPos))
        return _player->die();
    if (isInsideSnake(nextPos))
        return _player->die();
    if (isInsideApple(nextPos))
        return _player->grow(nextPos);
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
    for (auto line : _map) {
        for (auto entity : line) {
            _entities.push_back(entity);
        }
    }
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::SnakeGame::getTexts()
{
    _texts.clear();
    _texts.push_back(std::make_shared<Arcade::Text>("Score: " + std::to_string(_score), 0, 0));
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
            line.push_back(makeVerticalSides<SnakeWall>(width, row));
        else
            line.push_back(makeHorizontalSides<SnakeWall, SnakeVoid>(width, row));
        _map.push_back(line);
    }
}

bool Arcade::SnakeGame::isInsideWall(std::pair<int, int> pos)
{
    if (_map.at(pos.second).at(pos.first)->getChar() == '#')
        return true;
    return false;
}

bool Arcade::SnakeGame::isInsideSnake(std::pair<int, int> pos)
{
    for (auto body : _player->getBodies()) {
        if (body->getPos().at(0) == pos.first && body->getPos().at(1) == pos.second)
            return true;
    }
    return false;
}

bool Arcade::SnakeGame::isInsideApple(std::pair<int, int> pos)
{
    if (_map.at(pos.second).at(pos.first)->getChar() == '@')
        return true;
    return false;
}

std::pair<int, int> Arcade::SnakeGame::getNextPost(std::shared_ptr<SnakePlayer> player)
{
    std::vector<size_t> nextPos = _player->getHead()->getPos();

    switch ((Arcade::SnakePlayer::Rotation)_player.get()->getHead()->getRotation()) {
    case Arcade::SnakePlayer::Rotation::UP:
        nextPos[1]--;
        break;
    case Arcade::SnakePlayer::Rotation::RIGHT:
        nextPos[0]++;
        break;
    case Arcade::SnakePlayer::Rotation::DOWN:
        nextPos[1]++;
        break;
    case Arcade::SnakePlayer::Rotation::LEFT:
        nextPos[0]--;
        break;
    }
    return std::make_pair(nextPos[0], nextPos[1]);
}
