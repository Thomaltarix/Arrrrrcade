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
        size_t i = 0;
        for (auto body : enemy->getBodies()) {
            updateRotation(body, i, enemy->getBodies());
            _entities.push_back(body);
            i++;
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

void Arcade::Centipede::updateRotation(std::shared_ptr<CentipedeEnemyBody> body, size_t i,
                                        std::vector<std::shared_ptr<CentipedeEnemyBody>> bodies)
{
    if (i == 0)
        return;
    if (i == bodies.size() - 1)
        return;

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
        body.get()->setPath("assets/Centipede/angle");
        body.get()->setRotation((float)Arcade::FUP);
    }
    // Bottom to right and right to bottom
    else if (((y1 - 1 == y2 && x1 == x2) && (y3 == y2 && x3 - 1 == x2))
    || ((y1 == y2 && x1 - 1 == x2) && (y3 - 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Centipede/angle");
        body.get()->setRotation((float)Arcade::FDOWN);
    }
    // Bottom to left and left to bottom
    else if (((y1 - 1 == y2 && x1 == x2) && (y3 == y2 && x3 + 1 == x2))
    || ((y1 == y2 && x1 + 1 == x2) && (y3 - 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Centipede/angle");
        body.get()->setRotation((float)Arcade::FLEFT);
    }
    // Top to right and right to top
    else if (((y1 + 1 == y2 && x1 == x2) && (y3 == y2 && x3 - 1 == x2))
    || ((y1 == y2 && x1 - 1 == x2) && (y3 + 1 == y2 && x3 == x2))) {
        body.get()->setPath("assets/Centipede/angle");
        body.get()->setRotation((float)Arcade::FRIGHT);
    }
    // Simple body
    else
        body.get()->setPath("assets/Centipede/body");
    fixTailRotation(bodies);
}

void Arcade::Centipede::fixTailRotation(std::vector<std::shared_ptr<CentipedeEnemyBody>> bodies)
{
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