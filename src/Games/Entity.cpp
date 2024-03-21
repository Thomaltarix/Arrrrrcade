/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Entity
*/

#include "Entity.hpp"

// Color

Color::Color()
{
    _r = 255;
    _g = 255;
    _b = 255;
    _a = 255;
}

void Color::setColor(short r, short g, short b, short a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

short Color::getR()
{
    return _r;
}
short Color::getG()
{
    return _g;
}
short Color::getB()
{
    return _b;
}
short Color::getA()
{
    return _a;
}

//Entity

Entity::Entity()
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

void Entity::setPos(std::size_t x, std::size_t y)
{
    _pos[0] = x;
    _pos[1] = y;
}

void Entity::setSize(std::size_t x, std::size_t y)
{
    _size[0] = x;
    _size[1] = y;
}

void Entity::setChar(char c)
{
    _c = c;
}

void Entity::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Entity::setPath(const std::string &path)
{
    _path = path;
}

void Entity::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Entity::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Entity::getSize() const
{
    return _size;
}

int Entity::getChar() const
{
    return _c;
}

std::shared_ptr<IColor> Entity::getColor() const
{
    std::shared_ptr<IColor> color = std::make_shared<Color>();

    color.get()->setColor(_color->getR(), _color->getG(), _color->getB(), _color->getA());
    return color;
}

std::string Entity::getPath() const
{
    return _path;
}

float Entity::getRotation() const
{
    return _rotation;
}
