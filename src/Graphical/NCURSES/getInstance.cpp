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
        std::cout << "Loading foo ncurses ..." << std::endl;
    }


    std::unique_ptr<NCURSESlib> getInstance(void)
    {
        return std::make_unique<NCURSESlib>();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "ncurses closing ..." << std::endl;
    }
}
