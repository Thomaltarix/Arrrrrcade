/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Text
*/

#include "Text.hpp"

Text::Text() {}

Text::~Text() {}

// ------------------ SETTERS ------------------ //

void Text::setFontPath(const std::string &fontPath)
{
    _fontPath = fontPath;
}

void Text::setText(const std::string &text)
{
    _text = text;
}

void Text::setColor(std::unique_ptr<IColor> color)
{
    _color = std::move(color);
}

void Text::setPos(std::size_t x, std::size_t y)
{
    _pos[0] = x;
    _pos[1] = y;
}

void Text::setSize(std::size_t x)
{
    _size = x;
}

void Text::setRotation(float rotation)
{
    _rotation = rotation;
}

// ------------------ GETTERS ------------------ //

std::string Text::getFontPath()
{
    return _fontPath;
}

std::string Text::getText()
{
    return _text;
}

std::shared_ptr<IColor> Text::getColor() const
{
    std::shared_ptr<IColor> color = std::make_shared<Color>();

    color->setColor(_color->getR(), _color->getG(), _color->getB(), _color->getA());
    return color;
}

std::vector<std::size_t> Text::getPos() const
{
    return _pos;
}

std::size_t Text::getSize() const
{
    return _size;
}

float Text::getRotation() const
{
    return _rotation;
}
