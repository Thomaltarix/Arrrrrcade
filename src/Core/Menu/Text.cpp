/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Text
*/

#include "Text.hpp"

Arcade::Menu::Text::Text() {}

Arcade::Menu::Text::~Text() {}

// ------------------ SETTERS ------------------ //

void Arcade::Menu::Text::setFontPath(const std::string &fontPath)
{
    _fontPath = fontPath;
}

void Arcade::Menu::Text::setText(const std::string &text)
{
    _text = text;
}

void Arcade::Menu::Text::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Arcade::Menu::Text::setPos(std::size_t x, std::size_t y)
{
    _pos.push_back(x);
    _pos.push_back(y);
}

void Arcade::Menu::Text::setSize(std::size_t x)
{
    _size = x;
}

void Arcade::Menu::Text::setRotation(float rotation)
{
    _rotation = rotation;
}

// ------------------ GETTERS ------------------ //

std::string Arcade::Menu::Text::getFontPath()
{
    return _fontPath;
}

std::string Arcade::Menu::Text::getText()
{
    return _text;
}

std::shared_ptr<Arcade::IColor> Arcade::Menu::Text::getColor() const
{
    std::shared_ptr<IColor> color = std::make_shared<Color>();

    color->setColor(_color->getR(), _color->getG(), _color->getB(), _color->getA());
    return color;
}

std::vector<std::size_t> Arcade::Menu::Text::getPos() const
{
    return _pos;
}

std::size_t Arcade::Menu::Text::getSize() const
{
    return _size;
}

float Arcade::Menu::Text::getRotation() const
{
    return _rotation;
}
