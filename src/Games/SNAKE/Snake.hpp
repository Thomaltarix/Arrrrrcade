/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakeGame
*/

#pragma once

#include "AGame.hpp"
#include "SnakePlayer.hpp"
#include "Keys.hpp"
#include "Text.hpp"

#include <unordered_map>
#include <functional>
#include <time.h>
namespace Arcade {
    class SnakeGame : public AGame {
        public:
            SnakeGame();
            ~SnakeGame();

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
            bool _started;
            int _score;
            Map _map;
            clock_t _lastTick;

            // Entities
            std::shared_ptr<SnakeBackground> _background;
            std::unique_ptr<SnakePlayer> _player;
            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<IEntity>> _entities;

            // Key Events
            std::unordered_map<int, std::function<void()>> _keyEvents = {
                {Keys::Z, [this](){_player->move(Arcade::FUP);}},
                {Keys::S, [this](){_player->move(Arcade::FDOWN);}},
                {Keys::Q, [this](){_player->move(Arcade::FLEFT);}},
                {Keys::D, [this](){_player->move(Arcade::FRIGHT);}},
            };

            // Private functions
            void initMap(int width, int height);
            bool isInsideWall(std::pair<size_t, size_t> pos);
            bool isInsideSnake(std::pair<size_t, size_t> pos);
            bool isInsideApple(std::pair<size_t, size_t> pos);
            void spawnApple();
            void fixTailRotation();
            void updateRotation(std::shared_ptr<SnakeBody> body, size_t i);

            template <typename T>
            std::vector<std::shared_ptr<Arcade::IEntity>> makeVerticalSides(int width , int height)
            {
                auto line = std::vector<std::shared_ptr<IEntity>>();

                for (int i = 0; i < width; i++)
                    line.push_back(std::make_shared<T>(i, height));
                return line;
            };

            template <typename T1, typename T2>
            std::vector<std::shared_ptr<IEntity>> makeHorizontalSides(int width , int height)
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
