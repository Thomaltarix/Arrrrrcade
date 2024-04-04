/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Saveinfo
*/
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class InfoLoaderSaver {
    public:
        bool addScore(std::string gameName, std::string playerName, int score);

        int getHighestScoreForPlayer(std::vector<std::string> listGames, std::string gameName);
        std::vector<std::string> getHighestScores(std::vector<std::string> listGame, size_t number);

        ~InfoLoaderSaver() = default;
        InfoLoaderSaver();
    private:
        std::string _path;

        std::vector<std::string> getPlayerList();
        std::vector<std::pair<std::string, size_t>> sortScoreBoard(std::vector<std::pair<std::string, size_t>> list);
};
