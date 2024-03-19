/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml
*/

#include <iostream>
#include "SFML.hpp"
#include <memory>

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading SFML library ..." << std::endl;
    }

    std::unique_ptr<SFMLlib> getInstance()
    {
        return std::make_unique<SFMLlib>();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "SFML closing ..." << std::endl;
    }
}
