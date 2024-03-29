/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SnakeHead
*/

#include "CentipedeEntity.hpp"
// #include "CentipedePlayer.hpp"
#include "Centipede.hpp"

Arcade::CentipedeBackground::CentipedeBackground(std::size_t x, std::size_t y)
{
    this->setChar(' ');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 0, 255);
    this->setPath("assets/Centipede/background");
    this->setRotation((float)Arcade::FUP);
    this->setSize(725, 899);
    this->setPos(x, y);
}

Arcade::CentipedeShip::CentipedeShip(size_t x, size_t y)
{
    this->setChar('W');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 255, 0, 255);
    this->setPath("assets/Centipede/ship");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}

Arcade::CentipedeEnemyHead::CentipedeEnemyHead(size_t x, size_t y, Arcade::Rotation rotation)
{
    this->setChar('G');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("assets/Centipede/head");
    this->setRotation((float)rotation);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}

Arcade::CentipedeEnemyTail::CentipedeEnemyTail(size_t x, size_t y, Arcade::Rotation rotation)
{
    this->setChar('Q');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("assets/Centipede/tail");
    this->setRotation((float)rotation);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}

Arcade::CentipedeEnemyBody::CentipedeEnemyBody(size_t x, size_t y, Arcade::Rotation rotation)
{
    this->setChar('O');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("assets/Centipede/body");
    this->setRotation((float)rotation);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}

Arcade::CentipedeWall::CentipedeWall(std::size_t x, std::size_t y)
{   
    this->setChar('#');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 255, 255);
    this->setPath("");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}

Arcade::CentipedeVoid::CentipedeVoid(std::size_t x, std::size_t y)
{
    this->setChar(' ');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(0, 0, 0, 255);
    this->setPath("");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}

Arcade::CentipedeBox::CentipedeBox(size_t x, size_t y)
{
    this->setChar('X');
    this->setColor(std::make_unique<Arcade::Color>());
    this->getColor()->setColor(255, 0, 0, 255);
    this->setPath("assets/Centipede/box");
    this->setRotation((float)Arcade::FUP);
    this->setSize(29, 29);
    this->setPos(x + 2, y + 7);
}
