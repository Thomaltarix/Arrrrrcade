/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Saveinfo
*/
#pragma once
#include <iostream>

class InfoLoaderSaver {
    public:
        bool getInfos(std::string path);
        bool setInfos(int score, std::string path);

        int getScore() { return _score; } ;

        ~InfoLoaderSaver() = default;
        InfoLoaderSaver() = default;
    private:
        int _score;
};
