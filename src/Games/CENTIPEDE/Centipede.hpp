/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** centipede
*/

#pragma once

#include "AGame.hpp"
#include "CentipedePlayer.hpp"
#include "Keys.hpp"
#include "CentipedeEnemy.hpp"

#include <unordered_map>
#include <functional>

namespace Arcade {
    class Centipede : public AGame{
        public:
            Centipede();
            ~Centipede();

            //Game
            int startGame();
            int stopGame();
            int getScore();
            int simulate();

            //Event
            void catchKeyEvent(int key);
            void catchMousePosition(int x, int y) { (void) x; (void) y; };

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();

        private:
            //Centipede variables
            std::string _userName;
            bool _started;
            int _score;
            int _key;
            clock_t _generationClock;
            int _nbCentipede;
            int _nbWaves;

            //All Centipede Entities
            std::unique_ptr<CentipedePlayer> _player;
            std::vector<std::shared_ptr<CentipedeEnemy>> _enemies;
            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<IEntity>> _entities;
            std::shared_ptr<Arcade::CentipedeBackground> _background;

            void updateRotation(std::shared_ptr<CentipedeEnemyBody> body, size_t i,
            std::vector<std::shared_ptr<CentipedeEnemyBody>> bodies);
            void fixTailRotation(std::vector<std::shared_ptr<CentipedeEnemyBody>> bodies);
        
            std::unordered_map<int, std::function<void()>> _keyEvents = {
                {Keys::Z, [this](){_player->move(Arcade::FUP);}},
                {Keys::S, [this](){_player->move(Arcade::FDOWN);}},
                {Keys::Q, [this](){_player->move(Arcade::FLEFT);}},
                {Keys::D, [this](){_player->move(Arcade::FRIGHT);}},
            };

            //Map management
            Map _map;
            void initMap(int width, int height);

            //Simulations
            void simulateShoot();
            void simulateEnemies();
            void checkEndWaves();
            void simulateGenEnemies();
            void shoot();
            void moveShoot();
            void deleteShoot();
            bool isInsideEnemy(std::vector<size_t> pos);
            bool isInsideBox(std::vector<size_t> pos);
            void transformBox(std::vector<size_t> pos);
            void cutEnemy(std::vector<size_t> pos, size_t enemy);
    };
}
