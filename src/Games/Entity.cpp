/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Entity
*/

#include "Entity.hpp"

// Color

Arcade::Color::Color()
{
    _r = 255;
    _g = 255;
    _b = 255;
    _a = 255;
}

void Arcade::Color::setColor(short r, short g, short b, short a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

short Arcade::Color::getR()
{
    return _r;
}
short Arcade::Color::getG()
{
    return _g;
}
short Arcade::Color::getB()
{
    return _b;
}
short Arcade::Color::getA()
{
    return _a;
}

//Entity

Arcade::Entity::Entity()
{
    _pos.push_back(0);
    _pos.push_back(0);
    _size.push_back(0);
    _size.push_back(0);
    _c = 0;
    _color = std::make_unique<Color>();
    _path = "";
    _rotation = 0;
}

void Arcade::Entity::setPos(std::size_t x, std::size_t y)
{
    _pos[0] = x;
    _pos[1] = y;
}

void Arcade::Entity::setSize(std::size_t x, std::size_t y)
{
    _size[0] = x;
    _size[1] = y;
}

void Arcade::Entity::setChar(char c)
{
    _c = c;
}

void Arcade::Entity::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Entity::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Entity::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Entity::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Entity::getSize() const
{
    return _size;
}

int Arcade::Entity::getChar() const
{
    return _c;
}

std::shared_ptr<Arcade::IColor> Arcade::Entity::getColor() const
{
    std::shared_ptr<IColor> color = std::make_shared<Color>();

    color.get()->setColor(_color->getR(), _color->getG(), _color->getB(), _color->getA());
    return color;
}

std::string Arcade::Entity::getPath() const
{
    return _path;
}

float Arcade::Entity::getRotation() const
{
    return _rotation;
}
