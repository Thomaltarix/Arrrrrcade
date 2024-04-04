/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#include "Core.hpp"
#include <iostream>
#include <filesystem>
#include "Keys.hpp"
#include "Saveinfo.hpp"

Arcade::Core::Core()
{
    _isRunning = true;
    _idxGraphic = 0;
    _idxGame = 0;
    std::cout << "Core Created" << std::endl;
}

Arcade::Core::~Core()
{
    std::cout << "Core Deleted" << std::endl;
}

void Arcade::Core::start(const std::string & graphicLib)
{
    createlistsLibs(graphicLib);
    loadGraphic(_listGraphic[_idxGraphic]);
    _menu = std::make_unique<Menu::Menu>(_listGraphic, _listGame, graphicLib);
    _gameLib = std::move(_menu);
    gameLoop();
}

bool Arcade::Core::isCorrectFormat(const std::string & path)
{
    std::string prefix = "./lib/arcade_";
    std::string suffix = ".so";

    if (path.length() < 17)
        return false;
    if (path.compare(path.length() - suffix.length(), suffix.length(), suffix) == 0 &&
        path.compare(0, prefix.length(), prefix) == 0)
        return true;
    return false;
}

void Arcade::Core::createlistsLibs(const std::string & graphicLib)
{
    std::string path = "./lib/";
    IGame *tmpgame;
    IGraphic *tmpgraphic;

    for (const auto& file : std::filesystem::directory_iterator(path)) {
        if (!isCorrectFormat(file.path()))
            continue;
        _loaderGame.load(file.path());
        _loaderGraphic.load(file.path());
        tmpgame = _loaderGame.getInstance<IGame>("loadGameInstance");
        tmpgraphic = _loaderGraphic.getInstance<IGraphic>("loadGraphicInstance");
        if (tmpgame)
            _listGame.push_back(file.path());
        else if (tmpgraphic)
            _listGraphic.push_back(file.path());
        if (tmpgame)
            delete tmpgame;
        if (tmpgraphic)
            delete tmpgraphic;
    }
    auto it = std::find(_listGraphic.begin(), _listGraphic.end(), graphicLib);
    if (it != _listGraphic.end())
        _idxGraphic = it - _listGraphic.begin();
    else
        throw Error(graphicLib + " does not exist.");
}

void Arcade::Core::loadGraphic(const std::string & graphicLib)
{
    _loaderGraphic.load(graphicLib);
    _graphicLib = std::unique_ptr<IGraphic>{_loaderGraphic.getInstance<IGraphic>("loadGraphicInstance")};
    if (!_graphicLib)
        throw Error("failed to load Graphic Library (" + graphicLib + ")");
}

void Arcade::Core::loadGame(const std::string & gameLib)
{
    _loaderGame.load(gameLib);
    _gameLib = std::unique_ptr<IGame>{_loaderGame.getInstance<IGame>("loadGameInstance")};
    if (!_gameLib)
        throw Error("failed to load Graphic Library (" + gameLib + ")");
}

void Arcade::Core::gameLoop()
{
    _gameLib->startGame();
    while(_graphicLib->isWindowOpen() && _isRunning) {
        manageEvents();
        updateDraw();
        renderDraw();
    }
}

void Arcade::Core::manageEvents()
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

void Arcade::Core::commandExit()
{
    _isRunning = false;
}

void Arcade::Core::commandBackMenu()
{
    if (dynamic_cast<Menu::Menu*>(_gameLib.get()))
        return;
    saveScore();
    _gameLib->stopGame();
    _menu = std::make_unique<Menu::Menu>(_listGraphic, _listGame, _listGraphic[_idxGraphic]);
    _gameLib = std::move(_menu);
    _gameLib->startGame();
}

void Arcade::Core::commandNextGame()
{
    if (dynamic_cast<Menu::Menu*>(_gameLib.get()))
        return;
    saveScore();
    std::string userName = _gameLib->getUserName();
    _gameLib->stopGame();
    _gameLib.reset();
    if (_listGame.size() - 1 == _idxGame)
        _idxGame = 0;
    else
        _idxGame += 1;
    loadGame(_listGame[_idxGame]);
    _gameLib->setUserName(userName);
    _gameLib->startGame();
}

void Arcade::Core::commandNextGraphic()
{
    _graphicLib.reset();
    if (_listGraphic.size() - 1 == _idxGraphic)
        _idxGraphic = 0;
    else
        _idxGraphic += 1;
    loadGraphic(_listGraphic[_idxGraphic]);
}

void Arcade::Core::commandRestartGame()
{
    if (dynamic_cast<Menu::Menu*>(_gameLib.get()))
        return;
    saveScore();
    _gameLib->stopGame();
    _gameLib->startGame();
}

void Arcade::Core::updateDraw()
{
    int code;
    _graphicLib->clearWindow();
    code = _gameLib->simulate();
    if (code != 0) {
        if (!changeGameFromMenu(code))
            stopGame();
    }

    try {
        _graphicLib->playSound(_gameLib->getSounds());
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        _graphicLib->displayEntities(_gameLib->getEntities());
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        _graphicLib->displayText(_gameLib->getTexts());
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Arcade::Core::renderDraw()
{
    _graphicLib->displayWindow();
}

bool Arcade::Core::changeGameFromMenu(int code)
{
    std::string graphic;
    std::string game;
    std::string userName;

    if (dynamic_cast<Menu::Menu*>(_gameLib.get())) {
        if ((code % 10) - 1 >= (int)_listGame.size())
            throw Error("To much games : only 10 allowed");
        if ((code / 10) - 1 >= (int)_listGraphic.size())
            throw Error("To much graphiclib : only 10 allowed");
        _idxGame = (code % 10) - 1;
        _idxGraphic = (code / 10) - 1;
        game = _listGame[_idxGame];
        graphic = _listGraphic[_idxGraphic];
        userName = _gameLib->getUserName();
        _graphicLib.reset();
        _gameLib.reset();
        loadGraphic(graphic);
        loadGame(game);
        _gameLib->setUserName(userName);
        _gameLib->startGame();
        return true;
    }
    return false;
}

void Arcade::Core::stopGame()
{
    saveScore();
    _gameLib->stopGame();
    _menu = std::make_unique<Menu::Menu>(_listGraphic, _listGame, _listGraphic[_idxGraphic]);
    _gameLib = std::move(_menu);
    _gameLib->startGame();
}

void Arcade::Core::saveScore()
{
    InfoLoaderSaver saver;
    std::string gameName = _listGame[_idxGame];
    std::string userName = _gameLib->getUserName();
    if (!saver.addScore(gameName, userName, _gameLib->getScore()))
        std::cout << "save not work" << std::endl;
}
