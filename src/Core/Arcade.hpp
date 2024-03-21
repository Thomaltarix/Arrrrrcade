/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade class
*/

#pragma once

class Arcade {

    public:
        Arcade();
        ~Arcade() = default;
        int start(int argc, char **argv);

    private:
        bool isSuccessfulParsing(int argc, char **argv);
        void displayUsage();
};
