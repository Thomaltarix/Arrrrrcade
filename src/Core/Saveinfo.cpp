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

bool InfoLoaderSaver::getInfos(std::string path) {
    std::ifstream stream = std::ifstream(path);
    std::string line1;
    std::string line2;
    int score = 0;
    std::string username;
    std::stringstream tmp;

    if (!stream.is_open())
        return false;
    if(!std::getline(stream, line1))
        return false;
    tmp.str(line1);
    if(!(tmp >> score))
        return false;
    std::getline(stream, username);
    this->_score = score;
    this->_username = username;
    return true;
}

bool InfoLoaderSaver::setInfos(int score, std::string username, std::string path) {
    std::ofstream stream(path, std::ios::app);

    if (!stream.is_open())
        return false;
    stream << username << "=" << score << std::endl;
    stream.close();
    return true;
}
