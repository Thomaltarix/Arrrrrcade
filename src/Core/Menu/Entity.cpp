/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Entity
*/

#include "Entity.hpp"

// Color

Arcade::Menu::Color::Color()
{
    _r = 255;
    _g = 255;
    _b = 255;
    _a = 255;
}

void Arcade::Menu::Color::setColor(short r, short g, short b, short a)
{
    _r = r;
    _g = g;
    _b = b;
    _a = a;
}

short Arcade::Menu::Color::getR()
{
    return _r;
}
short Arcade::Menu::Color::getG()
{
    return _g;
}
short Arcade::Menu::Color::getB()
{
    return _b;
}
short Arcade::Menu::Color::getA()
{
    return _a;
}

//Entity

Arcade::Menu::Entity::Entity()
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

void Arcade::Menu::Entity::setPos(std::size_t x, std::size_t y)
{
    _pos.clear();
    _pos.push_back(x);
    _pos.push_back(y);
}

void Arcade::Menu::Entity::setSize(std::size_t x, std::size_t y)
{
    _size.clear();
    _size.push_back(x);
    _size.push_back(y);
}

void Arcade::Menu::Entity::setChar(char c)
{
    _c = c;
}

void Arcade::Menu::Entity::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Menu::Entity::setPath(const std::string &path)
{
    _path = path;
}

void Arcade::Menu::Entity::setRotation(float rotation)
{
    _rotation = rotation;
}

std::vector<std::size_t> Arcade::Menu::Entity::getPos() const
{
    return _pos;
}

std::vector<std::size_t> Arcade::Menu::Entity::getSize() const
{
    return _size;
}

int Arcade::Menu::Entity::getChar() const
{
    return _c;
}

std::shared_ptr<Arcade::IColor> Arcade::Menu::Entity::getColor() const
{
    std::shared_ptr<IColor> color = std::make_shared<Color>();

    color.get()->setColor(_color->getR(), _color->getG(), _color->getB(), _color->getA());
    return color;
}

std::string Arcade::Menu::Entity::getPath() const
{
    return _path;
}

float Arcade::Menu::Entity::getRotation() const
{
    return _rotation;
}
