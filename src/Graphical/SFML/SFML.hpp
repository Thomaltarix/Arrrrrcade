/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SFML_lib
*/

#pragma once

#include "AGraphic.hpp"
#include <SFML/Graphics.hpp>

class SFML_lib : public AGraphic {
    public:
        SFML_lib();
        ~SFML_lib() override;

        //Window
        bool isWindowOpen() const override;
        void closeWindow() override;
        void clearWindow() override;

        //Event
        int getKeyEvent() override;

        //Display
        void displayWindow() override;
        void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
        void displayText(std::vector<std::shared_ptr<IText>> texts) override;
        void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;

    private:
        sf::RenderWindow _window;
        sf::Event _event;
};
