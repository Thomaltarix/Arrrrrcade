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
    _player->deplace(_map, _key);
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
