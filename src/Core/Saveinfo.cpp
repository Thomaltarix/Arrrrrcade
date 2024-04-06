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

InfoLoaderSaver::InfoLoaderSaver()
{
    _path = "./score/score.mtt";
}

bool InfoLoaderSaver::addScore(std::string gameName, std::string playerName, int score)
{
    std::string path = _path;
    std::ofstream stream(path, std::ios::app);

    if (!stream.is_open())
        return false;
    stream << playerName << " " << gameName << " " << score << std::endl;
    stream.close();
    return true;
}

int InfoLoaderSaver::getHighestScoreForPlayer(std::vector<std::string> listGame, std::string playerName)
{
    std::ifstream stream(_path);
    std::string line;
    std::string tmp;
    std::vector<size_t> listScore = std::vector<size_t>(listGame.size(), 0);
    size_t sum = 0;

    if (!stream.is_open())
        return -1;
    while (std::getline(stream, line)) {
        std::stringstream ss(line);
        ss >> tmp;
        if (tmp == playerName) {
            ss >> tmp;
            for (size_t i = 0; i < listGame.size(); i++) {
                if (tmp == listGame[i]) {
                    ss >> tmp;
                    if (std::atoi(tmp.c_str()) > (int)listScore[i])
                        listScore[i] = std::atoi(tmp.c_str());
                }
            }
        }
    }
    stream.close();
    for (size_t i = 0; i < listScore.size(); i++)
        sum += listScore[i];
    return sum;
}

std::vector<std::string> InfoLoaderSaver::getHighestScores(std::vector<std::string> listGame, size_t number)
{
    std::vector<std::pair<std::string, size_t>> scoreBoard;
    std::vector<std::string> listPlayer = getPlayerList();
    std::vector<std::string> result;
    std::string tmp;
    int score = 0;

    for (size_t i = 0; i < listPlayer.size(); i++) {
        score = getHighestScoreForPlayer(listGame, listPlayer[i]);
        scoreBoard.push_back(std::make_pair(listPlayer[i], score));
    }
    scoreBoard = sortScoreBoard(scoreBoard);
    for (size_t i = 0; i < number; i++) {
        if (i >= scoreBoard.size())
            break;
        tmp = scoreBoard[i].first + ": " + std::to_string(scoreBoard[i].second);
        result.push_back(tmp);
    }
    return result;
}

std::vector<std::string> InfoLoaderSaver::getPlayerList()
{
    std::ifstream stream(_path);
    std::string line;
    std::string tmp;
    std::vector<std::string> listPlayer;

    if (!stream.is_open())
        return listPlayer;
    while (std::getline(stream, line)) {
        std::stringstream ss(line);
        ss >> tmp;
        if (std::find(listPlayer.begin(), listPlayer.end(), tmp) == listPlayer.end())
            listPlayer.push_back(tmp);
    }
    stream.close();
    return listPlayer;
}

std::vector<std::pair<std::string, size_t>> InfoLoaderSaver::sortScoreBoard(std::vector<std::pair<std::string, size_t>> scoreBoard)
{
    std::sort(scoreBoard.begin(), scoreBoard.end(), [](const std::pair<std::string, size_t> &a, const std::pair<std::string, size_t> &b) {
        return a.second > b.second;
    });
    return scoreBoard;
}
