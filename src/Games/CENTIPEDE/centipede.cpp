/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** centipede
*/

#include <iostream>

extern "C"
{
    __attribute__((constructor))
    static void initsharedlibrary()
    {
        std::cout << "Loading foo library ..." << std::endl;
    }

    __attribute__((destructor))
    static void destroysharedlibrary()
    {
        std::cout << "foo closing ..." << std::endl;
    }
}