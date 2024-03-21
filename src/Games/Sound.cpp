/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Sound
*/

#include "Sound.hpp"

Sound::Sound() {}

Sound::~Sound() {}

// ------------------ SETTERS ------------------ //

void Sound::setPathSound(const std::string &pathSound)
{
    _pathSound = pathSound;
}

void Sound::setVolume(float volume)
{
    _volume = volume;
}

void Sound::setStatus(int status)
{
    _status = status;
}

// ------------------ GETTERS ------------------ //

std::string Sound::getPathSound()
{
    return _pathSound;
}

float Sound::getVolume() const
{
    return _volume;
}

int Sound::getStatus() const
{
    return _status;
}
