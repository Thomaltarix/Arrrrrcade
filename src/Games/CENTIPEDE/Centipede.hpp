/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** centipede
*/

#pragma once

#include "AGame.hpp"

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

            std::vector<std::shared_ptr<ISound>> _sounds;
            std::vector<std::shared_ptr<IText>> _texts;
            std::vector<std::shared_ptr<IEntity>> _entities;

            Map _map;
            void initMap(int width, int height);

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
