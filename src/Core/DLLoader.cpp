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

DLLoader::~DLLoader()
{
    if (_handle != nullptr && dlclose(_handle) != 0)
        std::cerr << dlerror() << std::endl;
};

void DLLoader::load(const std::string &libso)
{
    if (_handle != nullptr && dlclose(_handle) != 0)
            std::cerr << dlerror() << std::endl;
    _handle = dlopen(libso.c_str(), RTLD_LAZY);
    if (!_handle)
        std::cerr << dlerror() << std::endl;
}
