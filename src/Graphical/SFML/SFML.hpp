/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** SFMLlib
*/

#pragma once

#include "AGraphic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

class SFMLlib : public AGraphic {
    public:
        SFMLlib();
        ~SFMLlib() override;

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
        std::unordered_map<std::string, sf::Texture> _textures;
        std::unordered_map<std::string, sf::Font> _fonts;
        std::unordered_map<std::string, sf::SoundBuffer> _soundBuffers;
        std::unordered_map<std::string, sf::Sound> _sounds;

        sf::Sprite getSprite(std::shared_ptr<IEntity> entity);
        sf::Text createText(std::shared_ptr<IText> text);
        void playSound(std::shared_ptr<ISound> sound, bool loop);

        const std::unordered_map<sf::Keyboard::Key, int> _keyMap = {
            {sf::Keyboard::A, 0},
            {sf::Keyboard::B, 1},
            {sf::Keyboard::C, 2},
            {sf::Keyboard::D, 3},
            {sf::Keyboard::E, 4},
            {sf::Keyboard::F, 5},
            {sf::Keyboard::G, 6},
            {sf::Keyboard::H, 7},
            {sf::Keyboard::I, 8},
            {sf::Keyboard::J, 9},
            {sf::Keyboard::K, 10},
            {sf::Keyboard::L, 11},
            {sf::Keyboard::M, 12},
            {sf::Keyboard::N, 13},
            {sf::Keyboard::O, 14},
            {sf::Keyboard::P, 15},
            {sf::Keyboard::Q, 16},
            {sf::Keyboard::R, 17},
            {sf::Keyboard::S, 18},
            {sf::Keyboard::T, 19},
            {sf::Keyboard::U, 20},
            {sf::Keyboard::V, 21},
            {sf::Keyboard::W, 22},
            {sf::Keyboard::X, 23},
            {sf::Keyboard::Y, 24},
            {sf::Keyboard::Z, 25},
            {sf::Keyboard::Escape, 26},
            {sf::Keyboard::Tab, 27},
            {sf::Keyboard::LShift, 28},
            {sf::Keyboard::LControl, 29},
            {sf::Keyboard::Space, 30},
            {sf::Keyboard::Enter, 31},
            {sf::Keyboard::BackSpace, 32},
            {sf::Keyboard::Up, 33},
            {sf::Keyboard::Down, 34},
            {sf::Keyboard::Left, 35},
            {sf::Keyboard::Right, 36},
            {sf::Keyboard::Num0, 37},
            {sf::Keyboard::Num1, 38},
            {sf::Keyboard::Num2, 39},
            {sf::Keyboard::Num3, 40},
            {sf::Keyboard::Num4, 41},
            {sf::Keyboard::Num5, 42},
            {sf::Keyboard::Num6, 43},
            {sf::Keyboard::Num7, 44},
            {sf::Keyboard::Num8, 45},
            {sf::Keyboard::Num9, 46}
        };
};
