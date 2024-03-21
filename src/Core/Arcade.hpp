/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade class
*/

#pragma once

#include "Core.hpp"

class Arcade {

    public:
        Arcade();
        ~Arcade() = default;
        int start(int argc, char **argv);

    private:
        Core _core;
        bool isSuccessfulParsing(int argc);
        void displayUsage();
};
