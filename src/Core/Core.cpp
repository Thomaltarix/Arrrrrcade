/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#include "Core.hpp"
#include <iostream>

Core::Core()
{
    std::cout << "Core Created" << std::endl;
}

Core::~Core()
{
    std::cout << "Core Deleted" << std::endl;
}

void Core::start(const std::string & graphicLib)
{
    loadGraphic(graphicLib);
}

void Core::loadGraphic(const std::string & graphicLib)
{
    _loader.load(graphicLib);
    _graphicLib = _loader.getInstance<IGraphic>();
    if (!_graphicLib)
        throw Error("failed to load Graphic Library (" + graphicLib + ")");
}
