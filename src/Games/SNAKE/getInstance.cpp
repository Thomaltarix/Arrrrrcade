/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** getInstance
*/

#include <iostream>
#include "Snake.hpp"
#include <memory>

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading Snake library ..." << std::endl;
    }

    std::unique_ptr<SnakeGame> getInstance()
    {
        return std::make_unique<SnakeGame>();
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "Snake closing ..." << std::endl;
    }
}
