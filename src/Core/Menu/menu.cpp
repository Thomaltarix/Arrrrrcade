/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#include "menu.hpp"
#include "Entity.hpp"
#include "Text.hpp"
#include "keys.hpp"

#include <iostream>

Arcade::Menu::Menu::Menu(std::vector<std::string> listGraphic, std::vector<std::string> listGame)
{
    _listGame = listGame;
    _listGraphic = listGraphic;
    _userName = "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
    _userNameIndex = 0;
}

Arcade::Menu::Menu::~Menu()
{

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
    createText(_userName, 5, 23, 24);
    createLibsTexts();
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
    _listText[0]->setText(_userName);
    return 0;
}

//Event

void Arcade::Menu::Menu::catchKeyEvent(int key)
{
    if (key == Arcade::BACKSPACE) {
        if (_userNameIndex != 0)
            _userNameIndex -= 2;
        _userName[_userNameIndex] = '_';
        return;
    }
    if (key >= Arcade::A && key <= Arcade::Z) {
        if (_userNameIndex != 30) {
            _userName[_userNameIndex] = 65 + key;
            _userNameIndex += 2;
        }
        return;
    }
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
    std::string path = "src/Core/Menu/assets/background";

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
    createButton(10, 26, 164, 76);
}

void Arcade::Menu::Menu::createUserName()
{
    createButton(4, 22, 492, 76);
}

void Arcade::Menu::Menu::createLibsButtons()
{
    std::size_t pos = 5;

    for (std::size_t i = 0; i < _listGraphic.size(); i++) {
        createButton(5, pos, 164, 76);
        pos += 4;
    }

    pos = 5;
    for (std::size_t i = 0; i < _listGame.size(); i++) {
        createButton(15, pos, 164, 76);
        pos += 4;
    }
}

void Arcade::Menu::Menu::createButton(  std::size_t posx, std::size_t posy,
                                        std::size_t sizex, std::size_t sizey)
{
    std::shared_ptr<IEntity> entity = std::make_shared<Entity>();
    std::unique_ptr<IColor> color = std::make_unique<Color>();
    std::string path = "src/Core/Menu/assets/button-idle";

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
    return _listText;
}

void Arcade::Menu::Menu::createLibsTexts()
{
    std::size_t pos = 6;
    std::string tmp;

    for (std::size_t i = 0; i < _listGraphic.size(); i++) {
        tmp = _listGraphic[i];
        tmp.erase(0, 13);
        tmp.erase(tmp.length() - 3, 3);
        createText(tmp, 6, pos, 18);
        pos += 4;
    }

    pos = 6;
    for (std::size_t i = 0; i < _listGame.size(); i++) {
        tmp = _listGame[i];
        tmp.erase(0, 13);
        tmp.erase(tmp.length() - 3, 3);
        createText(tmp, 16, pos, 18);
        pos += 4;
    }
}

void Arcade::Menu::Menu::createText(std::string text, std::size_t posx, std::size_t posy, std::size_t size)
{
    std::shared_ptr<IText> myText = std::make_shared<Text>();
    std::unique_ptr<IColor> color = std::make_unique<Color>();

    color->setColor(0, 0, 0, 255);

    myText->setColor(std::move(color));
    myText->setFontPath("src/Core/Menu/assets/SimplyMono-Bold");
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
