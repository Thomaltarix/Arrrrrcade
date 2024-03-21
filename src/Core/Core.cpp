/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#include "Core.hpp"
#include <iostream>
#include <filesystem>

Core::Core()
{
    _isRunning = true;
    _idxGraphic = 0;
    _idxGame = 0;
    std::cout << "Core Created" << std::endl;
}

Core::~Core()
{
    std::cout << "Core Deleted" << std::endl;
}

void Core::start(const std::string & graphicLib)
{
    createlistsLibs(graphicLib);
    for (std::size_t i = 0; i < _listGraphic.size(); i++)
        std::cout << "|" << _listGraphic[i] << "|" << std::endl;
    for (std::size_t i = 0; i < _listGame.size(); i++)
        std::cout << "|" << _listGame[i] << "|" << std::endl;
    loadGraphic(_listGraphic[_idxGraphic]);
    loadGame("./lib/arcade_snake.so");
    gameLoop();
}

void Core::createlistsLibs(const std::string & graphicLib)
{
    std::string path = "./lib/";

    for (const auto& file : std::filesystem::directory_iterator(path)) {
        _loaderGame.load(file.path());
        _loaderGraphic.load(file.path());
        if (_loaderGame.getInstance<IGame>("loadGameInstance"))
            _listGame.push_back(file.path());
        else if (_loaderGraphic.getInstance<IGraphic>("loadGraphicInstance"))
            _listGraphic.push_back(file.path());
    }
    auto it = std::find(_listGraphic.begin(), _listGraphic.end(), graphicLib);
    if (it != _listGraphic.end())
        _idxGraphic = it - _listGraphic.begin();
    else
        throw Error(graphicLib + " does not exist.");
}

void Core::loadGraphic(const std::string & graphicLib)
{
    _loaderGraphic.load(graphicLib);
    _graphicLib = _loaderGraphic.getInstance<IGraphic>("loadGraphicInstance");
    if (!_graphicLib)
        throw Error("failed to load Graphic Library (" + graphicLib + ")");
}

void Core::loadGame(const std::string & gameLib)
{
    _loaderGame.load(gameLib);
    _gameLib = _loaderGame.getInstance<IGame>("loadGameInstance");
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
        commandExit();
        break;
    case ONE:
        commandNextGraphic();
        break;
    case TWO:
        commandNextGame();
        break;
    case THREE:
        commandRestartGame();
        break;
    case FOUR:
        commandBackMenu();
        break;
    default:
        break;
    }
    _gameLib->catchKeyEvent(key);
}

void Core::commandExit()
{
    _isRunning = false;
}

void Core::commandBackMenu()
{

}

void Core::commandNextGame()
{

}

void Core::commandNextGraphic()
{
    _graphicLib = nullptr;
    if (_listGraphic.size() - 1 == _idxGraphic)
        _idxGraphic = 0;
    else
        _idxGraphic += 1;
    loadGraphic(_listGraphic[_idxGraphic]);
}

void Core::commandRestartGame()
{

}
