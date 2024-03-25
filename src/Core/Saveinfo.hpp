/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Saveinfo
*/
#pragma once
#include <iostream>

class Infos {
    public: 
        std::string username;
        int score;
        bool valid;
        Infos(std::string username, int score, bool isvalid) {
            this->username = username;
            this->score = score;
            this->valid = isvalid;
        }
};

class InfoLoaderSaver {
    public:
        Infos *getInfos(std::string path);
        bool setInfos(int score, std::string username, std::string path);
        ~InfoLoaderSaver() = default;
        InfoLoaderSaver() = default;
};
