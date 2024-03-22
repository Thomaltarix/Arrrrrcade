/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#include "menu.hpp"
#include "Entity.hpp"

Arcade::Menu::Menu()
{

}

Arcade::Menu::~Menu()
{

}

//Game

int Arcade::Menu::startGame()
{
    createEntityBackground();
    return 0;
}

int Arcade::Menu::stopGame()
{
    return 0;
}

int Arcade::Menu::getScore()
{
    return 0;
}

int Arcade::Menu::simulate()
{
    return 0;
}

//Event

void Arcade::Menu::catchKeyEvent(int key)
{
    (void) key;
}

//Display

std::vector<std::shared_ptr<Arcade::IEntity>> Arcade::Menu::getEntities()
{
    return _listEntities;
}

void Arcade::Menu::createEntityBackground()
{
    std::shared_ptr<IEntity> back = std::make_shared<Entity>();
    std::unique_ptr<IColor> color = std::make_unique<Color>();
    std::string path = "src/Games/MENU/assets/background";

    color->setColor(0, 0, 0, 255);

    back->setChar(' ');
    back->setColor(std::move(color));
    back->setPath(path);
    back->setPos(0, 0);
    back->setRotation(0);
    back->setSize(725, 899);

    _listEntities.push_back(std::move(back));
}

std::vector<std::shared_ptr<Arcade::IText>> Arcade::Menu::getTexts()
{
    std::vector<std::shared_ptr<Arcade::IText>> list;
    return list;
}

std::vector<std::shared_ptr<Arcade::ISound>> Arcade::Menu::getSounds()
{
    std::vector<std::shared_ptr<Arcade::ISound>> list;
    return list;
}
