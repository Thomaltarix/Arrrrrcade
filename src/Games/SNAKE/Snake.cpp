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
    initMap(19, 17);

    _player = std::make_shared<SnakePlayer>(10, 9, 4, SnakePlayer::RIGHT);

    for (auto body : player->getBodies())
        _map.at(body->getPos().y).at(body->getPos().x) = body;
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
    if (isInsideWall(getNextPost(_player)))
        return _player->die();
    if (isInsideSnake(getNextPost(_player)))
        return _player->die();
    if (isInsideApple(getNextPost(_player)))
        _player->move(int );
    _player->move();
    return 0;
}

void Arcade::SnakeGame::catchKeyEvent(int key)
{
    for (auto &event : _keyEvents) {
        if (event.first == key)
            event.second();
    }
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
    return false
}

bool Arcade::SnakeGame::isInsideApple(std::pair<int, int> pos)
{
    if (_map.at(pos.second).at(pos.first)->getChar() == '@')
        return true;
    return false;
}

std::pair<int, int> Arcade::SnakeGame::getNextPost(std::shared_ptr<SnakePlayer> player)
{
    std::pair<int, int> nextPos = player->getHead()->getPos();

    switch (player->getHead()->getRotation()) {
    case SnakePlayer::UP:
        nextPos.second--;
        break;
    case SnakePlayer::RIGHT:
        nextPos.first++;
        break;
    case SnakePlayer::DOWN:
        nextPos.second++;
        break;
    case SnakePlayer::LEFT:
        nextPos.first--;
        break;
    }
    return nextPos;
}
