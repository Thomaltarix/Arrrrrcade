/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakeHead
*/

#include "SnakeEntity.hpp"
#include "SnakePlayer.hpp"
#include "Snake.hpp"

Arcade::SnakeBody::SnakeBody(size_t x, size_t y, Arcade::Rotation rotation)
{
    this->setChar('O');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("assets/body");
    this->setRotation((float)rotation);
    this->setSize(1, 1);
    this->setPos(x, y);
}

Arcade::SnakeWall::SnakeWall(size_t x, size_t y)
{
    this->setChar('#');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("assets/wall");
    this->setRotation((float)Arcade::FUP);
    this->setSize(1, 1);
    this->setPos(x, y);
}

Arcade::SnakeVoid::SnakeVoid(size_t x, size_t y)
{
    this->setChar(' ');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 0, 255);
    this->setPath("assets/void");
    this->setRotation((float)Arcade::FUP);
    this->setSize(1, 1);
    this->setPos(x, y);
}

Arcade::SnakeBackground::SnakeBackground(size_t x, size_t y)
{
    this->setChar(' ');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 0, 255);
    this->setPath("assets/background");
    this->setRotation((float)Arcade::FUP);
    this->setSize(1, 1);
    this->setPos(x, y);
}

Arcade::SnakeApple::SnakeApple(size_t x, size_t y)
{
    this->setChar('@');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(255, 0, 0, 255);
    this->setPath("assets/apple");
    this->setRotation((float)Arcade::FUP);
    this->setSize(1, 1);
    this->setPos(x, y);
}
