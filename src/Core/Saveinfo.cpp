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

bool InfoLoaderSaver::getInfos(std::string path)
{
    std::ifstream stream = std::ifstream(path);
    std::string line;
    int score = 0;
    std::stringstream tmp;

    if (!stream.is_open())
        return false;
    if (!std::getline(stream, line)) {
        stream.close();
        return false;
    }
    score = atoi(line.c_str());
    std::cout << score << std::endl;
    this->_score = score;
    stream.close();
    return true;
}

bool InfoLoaderSaver::setInfos(int score, std::string path)
{
    int lastScore = 0;
    if (!getInfos(path))
        lastScore = 0;
    else
        lastScore = getScore();
    std::ofstream stream(path);

    if (!stream.is_open())
        return false;
    if (getScore() > score) {
        score = lastScore;
    }
    stream << score << std::endl;
    stream.close();
    return true;
}
