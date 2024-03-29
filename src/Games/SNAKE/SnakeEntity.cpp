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
    this->setPath("assets/Snake/body");
    this->setRotation((float)rotation);
    this->setSize(29, 29);
    this->setPos(2 + x, 10 + y);
}

Arcade::SnakeWall::SnakeWall(size_t x, size_t y)
{
    this->setChar('#');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("assets/Snake/void");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(2 + x, 10 + y);
}

Arcade::SnakeVoid::SnakeVoid(size_t x, size_t y)
{
    this->setChar(' ');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 0, 255);
    this->setPath("assets/Snake/void");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(2 + x, 10 + y);
}

Arcade::SnakeBackground::SnakeBackground()
{
    this->setChar(' ');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 0, 255);
    this->setPath("assets/Snake/background");
    this->setRotation((float)Arcade::FUP);
    this->setSize(725, 899);
    this->setPos(0, 0);
}

Arcade::SnakeApple::SnakeApple(size_t x, size_t y)
{
    this->setChar('@');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(255, 0, 0, 255);
    this->setPath("assets/Snake/apple");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(x, y);
}
