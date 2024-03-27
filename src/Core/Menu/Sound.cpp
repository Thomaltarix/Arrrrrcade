/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Sound
*/

#include "Sound.hpp"

Arcade::Menu::Sound::Sound() {}

Arcade::Menu::Sound::~Sound() {}

// ------------------ SETTERS ------------------ //

void Arcade::Menu::Sound::setPathSound(const std::string &pathSound)
{
    _pathSound = pathSound;
}

void Arcade::Menu::Sound::setVolume(float volume)
{
    _volume = volume;
}

void Arcade::Menu::Sound::setStatus(int status)
{
    _status = status;
}

// ------------------ GETTERS ------------------ //

std::string Arcade::Menu::Sound::getPathSound()
{
    return _pathSound;
}

float Arcade::Menu::Sound::getVolume() const
{
    return _volume;
}

int Arcade::Menu::Sound::getStatus() const
{
    return _status;
}
