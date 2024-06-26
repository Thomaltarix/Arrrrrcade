/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Centipede
*/

#include <iostream>
#include "Centipede.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading centipede ..." << std::endl;
    }

    Arcade::Centipede *loadGameInstance()
    {
        return new Arcade::Centipede();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "centipede closing ..." << std::endl;
    }
}
