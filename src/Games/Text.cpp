/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Text
*/

#include "Text.hpp"

Arcade::Text::Text() {}

Arcade::Text::~Text() {}

// ------------------ SETTERS ------------------ //

void Arcade::Text::setFontPath(const std::string &fontPath)
{
    _fontPath = fontPath;
}

void Arcade::Text::setText(const std::string &text)
{
    _text = text;
}

void Arcade::Text::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Text::setPos(std::size_t x, std::size_t y)
{
    _pos[0] = x;
    _pos[1] = y;
}

void Arcade::Text::setSize(std::size_t x)
{
    _size = x;
}

void Arcade::Text::setRotation(float rotation)
{
    _rotation = rotation;
}

// ------------------ GETTERS ------------------ //

std::string Arcade::Text::getFontPath()
{
    return _fontPath;
}

std::string Arcade::Text::getText()
{
    return _text;
}

std::shared_ptr<Arcade::IColor> Arcade::Text::getColor() const
{
    std::shared_ptr<IColor> color = std::make_shared<Color>();

    color->setColor(_color->getR(), _color->getG(), _color->getB(), _color->getA());
    return color;
}

std::vector<std::size_t> Arcade::Text::getPos() const
{
    return _pos;
}

std::size_t Arcade::Text::getSize() const
{
    return _size;
}

float Arcade::Text::getRotation() const
{
    return _rotation;
}
