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

typedef std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> Map;

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

            //UserName
            void setUserName(const std::string &name);
            std::string getUserName();

            //Display
            std::vector<std::shared_ptr<IEntity>> getEntities();
            std::vector<std::shared_ptr<IText>> getTexts();
            std::vector<std::shared_ptr<ISound>> getSounds();

        private:
            std::string _userName;
            bool _started;
            int _score;
            int _key;
            clock_t _generationClock;

            std::unique_ptr<CentipedePlayer> _player;
            std::vector<std::shared_ptr<CentipedeEnemy>> _enemies;
            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<IEntity>> _entities;
        
            std::unordered_map<int, std::function<void()>> _keyEvents = {
                {Keys::Z, [this](){_player->move(Arcade::FUP);}},
                {Keys::S, [this](){_player->move(Arcade::FDOWN);}},
                {Keys::Q, [this](){_player->move(Arcade::FLEFT);}},
                {Keys::D, [this](){_player->move(Arcade::FRIGHT);}},
            };

            Map _map;
            std::shared_ptr<Arcade::CentipedeBackground> _background;
            void initMap(int width, int height);

            void simulateShoot();
            bool isInsideEnemy(std::vector<size_t> pos);
            bool isInsideBox(std::vector<size_t> pos);
            void transformBox(std::vector<size_t> pos);
            void cutEnemy(std::vector<size_t> pos, size_t enemy);
    };
}
