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
    size_t i = 0;
    for (std::shared_ptr<SnakeBody> body : _player->getBodies()) {
        updateRotation(body, i);
        _entities.push_back(body);
        i++;
    }
    return _entities;
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::SnakeGame::getTexts()
{
    _texts.clear();
    // std::string score = "Score" + std::to_string(_score);
    // std::shared_ptr<Arcade::IText> text = std::make_shared<Arcade::Text>(score, 0, 0);
    // _texts.push_back(text);
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

void Arcade::SnakeGame::updateRotation(std::shared_ptr<SnakeBody> body, size_t i)
{
    if (i == 0)
        return;
    if (i == _player->getBodies().size() - 1)
        return;

    std::vector<std::shared_ptr<SnakeBody>> bodies = _player->getBodies();

    std::vector<size_t> previousPos = bodies.at(i - 1).get()->getPos();
    std::vector<size_t> currentPos = bodies.at(i).get()->getPos();
    std::vector<size_t> nextPos = bodies.at(i + 1).get()->getPos();
    size_t x1 = previousPos[0];
    size_t y1 = previousPos[1];
    size_t x2 = currentPos[0];
    size_t y2 = currentPos[1];
    size_t x3 = nextPos[0];
    size_t y3 = nextPos[1];

    // Top to left and left to top
    if (((y1 + 1 == y2 && x1 == x2) && (y3 == y2 && x3 + 1 == x2))
    || ((y1 == y2 && x1 + 1 == x2) && (y3 + 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Snake/angle");
        body.get()->setRotation((float)Arcade::FDOWN);
    }
    // Bottom to right and right to bottom
    else if (((y1 - 1 == y2 && x1 == x2) && (y3 == y2 && x3 - 1 == x2))
    || ((y1 == y2 && x1 - 1 == x2) && (y3 - 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Snake/angle");
        body.get()->setRotation((float)Arcade::FUP);
    }
    // Bottom to left and left to bottom
    else if (((y1 - 1 == y2 && x1 == x2) && (y3 == y2 && x3 + 1 == x2))
    || ((y1 == y2 && x1 + 1 == x2) && (y3 - 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Snake/angle");
        body.get()->setRotation((float)Arcade::FRIGHT);
    }
    // Top to right and right to top
    else if (((y1 + 1 == y2 && x1 == x2) && (y3 == y2 && x3 - 1 == x2))
    || ((y1 == y2 && x1 - 1 == x2) && (y3 + 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Snake/angle");
        body.get()->setRotation((float)Arcade::FLEFT);
    }
    // Simple body
    else
        body.get()->setPath("assets/Snake/body");
    fixTailRotation();
}

void Arcade::SnakeGame::fixTailRotation()
{
    std::vector<std::shared_ptr<SnakeBody>> bodies = _player->getBodies();
    size_t last = bodies.size() - 1;
    size_t lastx = bodies.at(last).get()->getPos()[0];
    size_t lasty = bodies.at(last).get()->getPos()[1];
    size_t prevx = bodies.at(last - 1).get()->getPos()[0];
    size_t prevy = bodies.at(last - 1).get()->getPos()[1];

    if (lastx == prevx && lasty == prevy + 1)
        bodies.at(last).get()->setRotation((float)Arcade::FUP);
    else if (lastx == prevx && lasty == prevy - 1)
        bodies.at(last).get()->setRotation((float)Arcade::FDOWN);
    else if (lastx == prevx + 1 && lasty == prevy)
        bodies.at(last).get()->setRotation((float)Arcade::FLEFT);
    else if (lastx == prevx - 1 && lasty == prevy)
        bodies.at(last).get()->setRotation((float)Arcade::FRIGHT);
}
