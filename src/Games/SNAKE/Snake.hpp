/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakeGame
*/

#pragma once

#include "AGame.hpp"
#include "SnakePlayer.hpp"
#include <unordered_map>
#include "Keys.hpp"

typedef std::vector<std::vector<std::shared_ptr<Arcade::IEntity>>> Map;

namespace Arcade {
    class SnakeGame : public AGame {
        public:

            SnakeGame();
            ~SnakeGame();

            //Game
            int startGame();
            int stopGame();
            int getScore() { return _score; }
            int simulate();

            //Event
            void catchKeyEvent(int key);

            //Display
            virtual std::vector<std::shared_ptr<IEntity>> getEntities() = 0;
            virtual std::vector<std::shared_ptr<IText>> getTexts() = 0;
            virtual std::vector<std::shared_ptr<ISound>> getSounds() = 0;
        private:
            bool _started;
            int _score;
            Map _map;
            std::shared_ptr<SnakePlayer> _player;
            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<IEntity>> _entities;

            std::unordered_map<int, std::function<void()>> _keyEvents = {
                {Keys::Z, [this](){_player->move(SnakePlayer::UP);}},
                {Keys::S, [this](){_player->move(SnakePlayer::DOWN);}},
                {Keys::Q, [this](){_player->move(SnakePlayer::LEFT);}},
                {Keys::D, [this](){_player->move(SnakePlayer::RIGHT);}},
            }

            void initMap(int width, int height);
            bool isInsideWall(std::pair<int, int> pos);
            bool isInsideSnake(std::pair<int, int> pos);
            bool isInsideApple(std::pair<int, int> pos);
            std::pair<int, int> getNextPost(std::shared_ptr<SnakePlayer> player);

            template <typename T>
            std::shared_ptr<Arcade::IEntity> makeVerticalSides(int width , int height)
            {
                auto line = std::vector<std::shared_ptr<IEntity>>();

                for (int i = 0; i < width; i++)
                    line.push_back(std::make_shared<T>(i, height));
                return line;
            };

            template <typename T1, typename T2>
            std::shared_ptr<IEntity> makeHorizontalSides(int width , int height)
            {
                auto line = std::vector<std::shared_ptr<IEntity>>();

                line.push_back(std::make_shared<T1>(0, height));
                for (int i = 1; i < width - 1; i++)
                    line.push_back(std::make_shared<T2>(i, height));
                line.push_back(std::make_shared<T1>(width - 1, height));
                return line;
            };
    };
}