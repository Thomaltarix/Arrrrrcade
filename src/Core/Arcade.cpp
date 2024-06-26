/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade class
*/

#include "Arcade.hpp"
#include <iostream>

Arcade::Arcade::Arcade()
{
}

int Arcade::Arcade::start(int argc, char **argv)
{
    if (!isSuccessfulParsing(argc))
        return 84;
    try {
        _core.start(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

bool Arcade::Arcade::isSuccessfulParsing(int argc)
{
    if (argc == 2)
        return true;
    displayUsage();
    return false;
}

void Arcade::Arcade::displayUsage()
{
    std::cout << "USAGE: ./arcade lib\n\t"
    "lib is the .so graphiclib to launch arcade with" <<std::endl;
}
