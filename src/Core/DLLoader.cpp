/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#include "DLLoader.hpp"
#include <iostream>

DLLoader::DLLoader()
{
    _handle = nullptr;
};

void DLLoader::load(const std::string &libso)
{
    _handle = dlopen(libso.c_str(), RTLD_LAZY);
    if (!_handle)
        std::cerr << dlerror() << std::endl;
}

void DLLoader::close(void)
{
    if (dlclose(_handle) != 0)
        std::cerr << dlerror() << std::endl;
}
