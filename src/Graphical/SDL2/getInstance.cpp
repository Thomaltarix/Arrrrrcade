/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2 getInstance
*/

#include <iostream>
#include <memory>
#include "sdl2.hpp"

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading SDL2 library ..." << std::endl;
    }

    std::unique_ptr<SDL2lib> getInstance(void)
    {
        return std::make_unique<SDL2lib>();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "SDL2 closing ..." << std::endl;
    }
}