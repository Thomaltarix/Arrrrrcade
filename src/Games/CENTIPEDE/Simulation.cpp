/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** centipede
*/

#include "Centipede.hpp"
#include "Rules.hpp"

//Simulations

int Arcade::Centipede::simulate()
{
    _player->moveInMap(_map, _key);
    if (_player->isInsideCentipede(_enemies))
        return -1;
    simulateShoot();
    simulateEnemies();
    _map[_player->getBody()->getPos()[0] - 2][_player->getBody()->getPos()[1] - 7] = _player->getBody();
    checkEndWaves();
    simulateGenEnemies();
    return 0;
}

void Arcade::Centipede::simulateEnemies()
{
    for (size_t enemy = 0; enemy < _enemies.size(); enemy++) {
        _enemies[enemy]->simulate(_map);
        for (size_t body = 0; body < _enemies[enemy]->getBodies().size(); body++) {
            if (_enemies[enemy]->getBodies()[body]->getPos()[1] - 7 == MAP_HEIGHT - 1) {
                _score -= 20;
                _enemies.erase(_enemies.begin() + enemy);
            }
        }
    }
}

void Arcade::Centipede::checkEndWaves()
{
    if (_nbCentipede == WAVES_TO_WIN && _enemies.empty()) {
        _score += 100 * _nbWaves;
        _nbWaves += 1;
        _nbCentipede = 0;
        _map.clear();
        this->initMap(MAP_WIDTH, MAP_HEIGHT);
    }
}

void Arcade::Centipede::simulateGenEnemies()
{
    clock_t currentTick = clock();
    if ((float)(currentTick - _generationClock) / CLOCKS_PER_SEC < (GEN_CENTIPEDE - _nbWaves) || _nbCentipede == WAVES_TO_WIN)
        return;
    _generationClock = clock();
    _enemies.push_back(std::make_shared<CentipedeEnemy>(SIZE_CENTIPEDE, 1, SIZE_CENTIPEDE, Arcade::FRIGHT, CENTIPEDE_SPEED + _nbWaves));
    _nbCentipede += 1;
}

void Arcade::Centipede::simulateShoot()
{
    shoot();
    moveShoot();
    deleteShoot();
}

void Arcade::Centipede::shoot()
{
    if (_key == SPACE && !_player->getShoot()->isShoot()) {

        std::vector<size_t> PlayerPos = _player->getBody()->getPos();

        _map[PlayerPos[0] - 2][PlayerPos[1] - 8] = _player->getShoot()->getShoot();
        _player->getShoot()->getShoot()->setPos(PlayerPos[0], PlayerPos[1] - 1);
        _player->getShoot()->setIsShoot(true);
    }
}

void Arcade::Centipede::moveShoot()
{
    if (_player->getShoot()->simulate()) {

        std::vector<size_t> ShootPos = _player->getShoot()->getShoot()->getPos();

        _map[ShootPos[0] - 2][ShootPos[1] - 7] = _player->getShoot()->getShoot();
        _map[ShootPos[0] - 2][ShootPos[1] - 6] = std::make_shared<CentipedeVoid>(ShootPos[0] - 2, ShootPos[1] - 6);

        if (isInsideEnemy(ShootPos)) {
            _map[ShootPos[0] - 2][ShootPos[1] - 7] = std::make_shared<CentipedeBox>(ShootPos[0] - 2, ShootPos[1] - 7);
            _player->getShoot()->setIsShoot(false);
            _player->getShoot()->setWasShoot(false);
        } else if (isInsideBox(ShootPos)) {
            transformBox(ShootPos);
        }
    }
}

void Arcade::Centipede::deleteShoot()
{
    if (!_player->getShoot()->isShoot() && _player->getShoot()->wasShoot()) {

        std::vector<size_t> ShootPos = _player->getShoot()->getShoot()->getPos();

        _map[ShootPos[0] - 2][ShootPos[1] - 7] =
        std::make_shared<CentipedeVoid>(ShootPos[0] - 2, ShootPos[1] - 7);
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
