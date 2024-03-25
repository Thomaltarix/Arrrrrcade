/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Saveinfo
*/
#include "Saveinfo.hpp"
#include <iostream>
#include <fstream> 
#include <sstream>

Infos *InfoLoaderSaver::getInfos(std::string path) {
    std::ifstream stream = std::ifstream(path);
    std::string line1;
    std::string line2;
    int score = 0;
    std::string username;
    std::stringstream tmp;

    if (!stream.is_open())
        return NULL;
    if(!std::getline(stream, line1))
        return NULL;
    tmp.str(line1);
    if(!(tmp >> score))
        return NULL;
    std::getline(stream, username);
    return new Infos(username, score, false);
}

bool InfoLoaderSaver::setInfos(int score, std::string username, std::string path) {
    std::ofstream stream(path);

    if (!stream.is_open())
        return false;
    stream << score << std::endl << username << std::endl;
    stream.close();
    return true;
}
