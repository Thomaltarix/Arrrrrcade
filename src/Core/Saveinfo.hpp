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
        bool setInfos(int score, std::string username, std::string path);
        ~InfoLoaderSaver() = default;
        InfoLoaderSaver() = default;
    private:
        std::string _username;
        int _score;
};
