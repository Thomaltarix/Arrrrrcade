/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#include "Menu.hpp"
#include "Entity.hpp"
#include "Text.hpp"
#include "Keys.hpp"
#include <algorithm>
#include <iostream>
#include "../Saveinfo.hpp"

Arcade::Menu::Menu::Menu(   std::vector<std::string> listGraphic,
                            std::vector<std::string> listGame,
                            std::string selectedGraphic)
{
    _isPlayPressed = false;
    _listGame = listGame;
    _listGraphic = listGraphic;
    _userNameDisplay = "_ _ _ _ _ _ _ _ _ _";
    _userName = "";
    _userNameIndex = 0;
    _selectedGraphic = selectedGraphic;
    _selectedGame = "";
}

//Game

int Arcade::Menu::Menu::startGame()
{
    //Entities creation
    createEntityBackground();
    createEntityPlay();
    createUserName();
    createLibsButtons();
    //Text creation
    createText(_userNameDisplay, 5, 23, 24);
    createLibsTexts();

    _cursor.push_back(3);
    _cursor.push_back(1);

    return 0;
}

int Arcade::Menu::Menu::stopGame()
{
    return 0;
}

int Arcade::Menu::Menu::getScore()
{
    return 0;
}

int Arcade::Menu::Menu::simulate()
{
    int returnCode = 0;

    _listText[0]->setText(_userNameDisplay);
    if (_isPlayPressed && _selectedGame != "" && _selectedGraphic != "" && _userName != "") {
        for (int i = 0; i < (int)_listGraphic.size(); i++) {
            if (_selectedGraphic == _listGraphic[i])
                returnCode += (i+1) * 10;
        }
        for (int i = 0; i < (int)_listGame.size(); i++) {
            if (_selectedGame == _listGame[i])
                returnCode += (i+1);
        }
    }
    _isPlayPressed = false;
    return returnCode;
}

//Event

void Arcade::Menu::Menu::catchKeyEvent(int key)
{
    if (key == Arcade::BACKSPACE) {
        if (_userNameIndex != 0)
            _userNameIndex -= 2;
        _userNameDisplay[_userNameIndex] = '_';
        if (!_userName.empty())
            _userName.pop_back();
        return;
    }
    if (key >= Arcade::A && key <= Arcade::Z) {
        if (_userNameIndex != 20) {
            _userNameDisplay[_userNameIndex] = 65 + key;
            _userName += _userNameDisplay[_userNameIndex];
            _userNameIndex += 2;
        }
        return;
    }
    handleEnterKey(key);
    handleArrowKey(key);
}

bool Arcade::Menu::Menu::isOnText(std::shared_ptr<Arcade::IEntity> entity, int x, int y)
{
    if ((int)(entity->getPos()[0]) <= x && x <= (int)(entity->getPos()[0]) + (int)(entity->getSize()[0] / 29) &&
        (int)(entity->getPos()[1]) <= y && y <= (int)(entity->getPos()[1]) + (int)(entity->getSize()[1] / 29))
        return true;
    return false;
}

void Arcade::Menu::Menu::catchMousePosition(int x, int y)
{
    for (size_t i = 1; i < _listEntities.size(); i++) {
        if (i == 2)
            continue;
        if (isOnText(_listEntities[i], x, y)) {
            _cursor[0] = 3;
            _cursor[1] = 1;
            if (i > 2 && i <= 2 + _listGraphic.size()) {
                _cursor[0] = 1;
                _cursor[1] = i - _listGraphic.size() + 1;
            }
            if (i > 2 + _listGraphic.size() && i <= 2 + _listGraphic.size() + _listGame.size()) {
                _cursor[0] = 2;
                _cursor[1] = i - _listGame.size() - _listGraphic.size();
            }
            handleEnterKey(Arcade::ENTER);
            return;
        }
    }
}

void Arcade::Menu::Menu::handleEnterKey(int key)
{
    std::vector<std::size_t> tmp = _cursor;

    if (key == Arcade::ENTER) {
        changeButtonState(BUTTON_PRESSED);
        if (_cursor[0] == 1 && _selectedGraphic != _listGraphic[_cursor[1] - 1]) {
            for (std::size_t i = 0; i < _listGraphic.size(); i++) {
                if (_selectedGraphic == _listGraphic[i]) {
                    _cursor[1] = i + 1;
                    _selectedGraphic = _listGraphic[tmp[1] - 1];
                    changeButtonState(BUTTON_IDLE);
                }
            }
            _selectedGraphic = _listGraphic[tmp[1] - 1];
            _cursor = tmp;
        }
        if (_cursor[0] == 2 && _selectedGame != _listGame[_cursor[1] - 1]) {
            for (std::size_t i = 0; i < _listGame.size(); i++) {
                if (_selectedGame == _listGame[i]) {
                    _cursor[1] = i + 1;
                    _selectedGraphic = _listGraphic[tmp[1] - 1];
                    changeButtonState(BUTTON_IDLE);
                }
            }
            _selectedGame = _listGame[tmp[1] - 1];
            _cursor = tmp;
        }
        if (_cursor[0] == 3) {
            _isPlayPressed = true;
        }
    }
}

void Arcade::Menu::Menu::handleArrowKey(int key)
{
    switch (key)
    {
    case Arcade::UP:
        keyUp();
        break;
    case Arcade::DOWN:
        keyDown();
        break;
    case Arcade::LEFT:
        keyLeft();
        break;
    case Arcade::RIGHT:
        keyRight();
        break;
    default:
        break;
    }
}

void Arcade::Menu::Menu::keyUp()
{
    if (_cursor[0] == 3) {
        changeButtonState(BUTTON_IDLE);
        _cursor[0] = 1;
        _cursor[1] = _listGraphic.size();
        changeButtonState(BUTTON_SELECTED);
        return;
    }
    if (_cursor[0] == 2) {
        if (_cursor[1] != 1) {
            changeButtonState(BUTTON_IDLE);
            _cursor[1] -= 1;
            changeButtonState(BUTTON_SELECTED);
        }
        return;
    }
    if (_cursor[0] == 1) {
        if (_cursor[1] != 1) {
            changeButtonState(BUTTON_IDLE);
            _cursor[1] -= 1;
            changeButtonState(BUTTON_SELECTED);
        }
        return;
    }
}

void Arcade::Menu::Menu::keyDown()
{
    if (_cursor[0] == 3)
        return;
    if (_cursor[0] == 2) {
        changeButtonState(BUTTON_IDLE);
        if (_cursor[1] != _listGame.size())
            _cursor[1] += 1;
        else {
            _cursor[0] = 3;
            _cursor[1] = 1;
        }
        changeButtonState(BUTTON_SELECTED);
        return;
    }
    if (_cursor[0] == 1) {
        changeButtonState(BUTTON_IDLE);
        if (_cursor[1] != _listGraphic.size())
            _cursor[1] += 1;
        else {
            _cursor[0] = 3;
            _cursor[1] = 1;
        }
        changeButtonState(BUTTON_SELECTED);
        return;
    }
}

void Arcade::Menu::Menu::keyLeft()
{
    if (_cursor[0] == 3)
        return;
    if (_cursor[0] == 1)
        return;
    if (_cursor[0] == 2) {
        if (_listGraphic.size() == 0)
            return;
        changeButtonState(BUTTON_IDLE);
        _cursor[0] = 1;
        if (_cursor[1] > _listGraphic.size())
            _cursor[1] = _listGraphic.size();
        changeButtonState(BUTTON_SELECTED);
    }
}

void Arcade::Menu::Menu::keyRight()
{
    if (_cursor[0] == 3)
        return;
    if (_cursor[0] == 2)
        return;
    if (_cursor[0] == 1) {
        if (_listGame.size() == 0)
            return;
        changeButtonState(BUTTON_IDLE);
        _cursor[0] = 2;
        if (_cursor[1] > _listGame.size())
            _cursor[1] = _listGame.size();
        changeButtonState(BUTTON_SELECTED);
    }
}

void Arcade::Menu::Menu::changeButtonState(std::string path)
{
    if (path == BUTTON_IDLE) {
        if (_cursor[0] == 1 && _listGraphic[_cursor[1] - 1] == _selectedGraphic)
            path = BUTTON_PRESSED;
        if (_cursor[0] == 2 && _listGame[_cursor[1] - 1] == _selectedGame)
            path = BUTTON_PRESSED;
    }
    if (_cursor[0] == 3)
        _listEntities[1]->setPath(path);
    if (_cursor[0] == 1)
        _listEntities[2 + _cursor[1]]->setPath(path);
    if (_cursor[0] == 2)
        _listEntities[2 + _listGraphic.size() + _cursor[1]]->setPath(path);
}

//Display

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::Menu::Menu::getEntities()
{
    return _listEntities;
}

void Arcade::Menu::Menu::createEntityBackground()
{
    std::shared_ptr<IEntity> back = std::make_shared<Entity>();
    std::unique_ptr<IColor> color = std::make_unique<Color>();
    std::string path = "assets/menu/background";

    color->setColor(0, 0, 0, 255);

    back->setChar(' ');
    back->setColor(std::move(color));
    back->setPath(path);
    back->setPos(0, 0);
    back->setRotation(0);
    back->setSize(725, 899);

    _listEntities.push_back(std::move(back));
}

void Arcade::Menu::Menu::createEntityPlay()
{
    createButton(10, 26, 164, 76, BUTTON_SELECTED);
}

void Arcade::Menu::Menu::createUserName()
{
    createButton(4, 23, 492, 76, BUTTON_IDLE);
}

void Arcade::Menu::Menu::createLibsButtons()
{
    std::size_t pos = 7;

    for (std::size_t i = 0; i < _listGraphic.size(); i++) {
        if (_listGraphic[i] == _selectedGraphic)
            createButton(5, pos, 164, 76, BUTTON_PRESSED);
        else
            createButton(5, pos, 164, 76, BUTTON_IDLE);
        pos += 3;
    }

    pos = 7;
    for (std::size_t i = 0; i < _listGame.size(); i++) {
        createButton(14, pos, 164, 76, BUTTON_IDLE);
        pos += 3;
    }
}

void Arcade::Menu::Menu::createButton(  std::size_t posx, std::size_t posy,
                                        std::size_t sizex, std::size_t sizey,
                                        std::string path)
{
    std::shared_ptr<IEntity> entity = std::make_shared<Entity>();
    std::unique_ptr<IColor> color = std::make_unique<Color>();

    color->setColor(0, 0, 0, 255);

    entity->setChar(' ');
    entity->setColor(std::move(color));
    entity->setPath(path);
    entity->setPos(posx, posy);
    entity->setRotation(0);
    entity->setSize(sizex, sizey);

    _listEntities.push_back(std::move(entity));
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::Menu::Menu::getTexts()
{
    InfoLoaderSaver saver;
    _listText.clear();

    // Add start game
    createText("Play", 11, 27, 24);

    // Add user name
    createText(_userNameDisplay, 6, 24, 28);
    createLibsTexts();

    // Add highest scores
    int scoreNumber = 3;
    std::string gameName = "Best scores:";
    createText(gameName, 4, 2, 24);
    std::vector<std::string> scores = saver.getHighestScores(_listGame, scoreNumber);
    if (scores.size() == 0)
        scores.push_back("0");
    for (std::size_t i = 0; i < scores.size(); i++) {
        createText(scores[i], 16, 2 + i, 24);
    }

    // Add user score
    int listPlayer = saver.getHighestScoreForPlayer(_listGame, _userName);
    if (listPlayer == -1)
        listPlayer = 0;
    gameName = "Your score: " + std::to_string(listPlayer);
    createText(gameName, 9, 22, 24);
    return _listText;
}

void Arcade::Menu::Menu::createLibsTexts()
{
    std::size_t pos = 8;
    std::string tmp;

    for (std::size_t i = 0; i < _listGraphic.size(); i++) {
        tmp = _listGraphic[i];
        tmp.erase(0, 13);
        tmp.erase(tmp.length() - 3, 3);
        createText(tmp, 6, pos, 18);
        pos += 3;
    }

    pos = 8;
    for (std::size_t i = 0; i < _listGame.size(); i++) {
        tmp = _listGame[i];
        tmp.erase(0, 13);
        tmp.erase(tmp.length() - 3, 3);
        createText(tmp, 15, pos, 18);
        pos += 3;
    }
}

void Arcade::Menu::Menu::createText(std::string text, std::size_t posx, std::size_t posy, std::size_t size)
{
    std::shared_ptr<IText> myText = std::make_shared<Text>();
    std::unique_ptr<IColor> color = std::make_unique<Color>();

    color->setColor(0, 0, 0, 255);

    myText->setColor(std::move(color));
    myText->setFontPath("assets/menu/SimplyMono-Bold");
    myText->setPos(posx, posy);
    myText->setRotation(0);
    myText->setSize(size);
    myText->setText(text);

    _listText.push_back(std::move(myText));
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::Menu::Menu::getSounds()
{
    std::vector<std::shared_ptr<Arcade::ISound>> list;
    return list;
}

void Arcade::Menu::Menu::setUserName(const std::string &name)
{
    _userName = name;
}

std::string Arcade::Menu::Menu::getUserName()
{
    return _userName;
}
