/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu
*/

#include <iostream>
#include "menu.hpp"
#include <memory>

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading Menu library ..." << std::endl;
    }

    std::unique_ptr<Arcade::Menu> loadGameInstance()
    {
        return std::make_unique<Arcade::Menu>();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Menu closing ..." << std::endl;
    }
}
