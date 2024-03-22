/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Sound
*/

#include "Sound.hpp"

Arcade::Sound::Sound() {}

Arcade::Sound::~Sound() {}

// ------------------ SETTERS ------------------ //

void Arcade::Sound::setPathSound(const std::string &pathSound)
{
    _pathSound = pathSound;
}

void Arcade::Sound::setVolume(float volume)
{
    _volume = volume;
}

void Arcade::Sound::setStatus(int status)
{
    _status = status;
}

// ------------------ GETTERS ------------------ //

std::string Arcade::Sound::getPathSound()
{
    return _pathSound;
}

float Arcade::Sound::getVolume() const
{
    return _volume;
}

int Arcade::Sound::getStatus() const
{
    return _status;
}
