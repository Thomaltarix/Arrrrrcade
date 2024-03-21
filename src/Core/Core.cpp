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
    _isRunning = true;
    std::cout << "Core Created" << std::endl;
}

Core::~Core()
{
    std::cout << "Core Deleted" << std::endl;
}

void Core::start(const std::string & graphicLib)
{
    loadGraphic(graphicLib);
    loadGame("./lib/arcade_snake.so");
    gameLoop();
}

void Core::loadGraphic(const std::string & graphicLib)
{
    _loaderGraphic.load(graphicLib);
    _graphicLib = _loaderGraphic.getInstance<IGraphic>();
    if (!_graphicLib)
        throw Error("failed to load Graphic Library (" + graphicLib + ")");
}

void Core::loadGame(const std::string & gameLib)
{
    _loaderGame.load(gameLib);
    _gameLib = _loaderGame.getInstance<IGame>();
    if (!_gameLib)
        throw Error("failed to load Graphic Library (" + gameLib + ")");
}

void Core::gameLoop()
{
    _gameLib->startGame();
    while(_graphicLib->isWindowOpen() && _isRunning) {
        manageEvents();
        // updateDraw();
        // renderDraw();
    }
}

void Core::manageEvents()
{
    int key = _graphicLib->getKeyEvent();

    switch (key)
    {
    case ESCAPE:
        _isRunning = false;
        break;
    default:
        break;
    }
    _gameLib->catchKeyEvent(key);
}
