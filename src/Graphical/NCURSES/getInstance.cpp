/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses
*/

#include <iostream>
#include "ncurses.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading ncurses ..." << std::endl;
    }

    Arcade::NCURSESlib *loadGraphicInstance()
    {
        return new Arcade::NCURSESlib();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "ncurses closing ..." << std::endl;
    }
}
