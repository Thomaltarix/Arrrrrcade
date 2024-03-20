/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade class
*/

#include "Arcade.hpp"
#include <iostream>

Arcade::Arcade()
{
}

int Arcade::start(int argc, char **argv)
{
    if (!isSuccessfulParsing(argc, argv))
        return 84;
    return 0;
}

bool Arcade::isSuccessfulParsing(int argc, char **argv)
{
    (void) argv;
    if (argc != 2) {
        displayUsage();
        return false;
    }
    return 0;
}

void Arcade::displayUsage()
{
    std::cout << "USAGE: ./arcade lib\n\t"
    "lib is the .so graphiclib to launch arcade with" <<std::endl;
}
