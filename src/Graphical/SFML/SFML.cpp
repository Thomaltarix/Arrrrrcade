/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml
*/

#include "SFML.hpp"

SFMLlib::SFMLlib()
{
    if (isWindowOpen() == true)
        closeWindow();
    _window.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Close);
    _window.setFramerateLimit(60);
    if (!isWindowOpen())
        throw Error("SFML: Failed to create window");

    _event = sf::Event();
}

SFMLlib::~SFMLlib()
{
    closeWindow();
}

// ------------------ WINDOW ------------------ //

bool SFMLlib::isWindowOpen() const
{
    return _window.isOpen();
}

void SFMLlib::closeWindow()
{
    _window.close();
    if (isWindowOpen())
        throw Error("SFML: Failed to close window");
}

void SFMLlib::clearWindow()
{
    _window.clear();
}

// ------------------ EVENT ------------------ //

int SFMLlib::getKeyEvent()
{
    return 0;
}

// ------------------ DISPLAY ------------------ //

void SFMLlib::displayWindow()
{
    _window.display();
}

void SFMLlib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
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
