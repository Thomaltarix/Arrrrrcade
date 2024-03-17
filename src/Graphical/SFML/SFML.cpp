/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml
*/

#include "SFML.hpp"

SFML_lib::SFML_lib()
{
    if (isWindowOpen() == true)
        closeWindow();
    _window.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Close);
    _window.setFramerateLimit(60);
    if (!isWindowOpen())
        throw Error("SFML: Failed to create window");

    _event = sf::Event();
}

SFML_lib::~SFML_lib()
{
    closeWindow();
}

// ------------------ WINDOW ------------------ //

bool SFML_lib::isWindowOpen() const
{
    return _window.isOpen();
}

void SFML_lib::closeWindow()
{
    _window.close();
    if (isWindowOpen())
        throw Error("SFML: Failed to close window");
}

void SFML_lib::clearWindow()
{
    _window.clear();
}

// ------------------ EVENT ------------------ //

int SFML_lib::getKeyEvent()
{
    return 0;
}

// ------------------ DISPLAY ------------------ //

void SFML_lib::displayWindow()
{
    _window.display();
}

void SFML_lib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    (void) entities;
}

void SFML_lib::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    (void) texts;
}

void SFML_lib::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void) sounds;
}
