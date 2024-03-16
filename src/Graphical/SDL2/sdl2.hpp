/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2
*/

#pragma once

#include "AGraphic.hpp"
#include <SDL2/SDL.h>

class SDL2_lib : public AGraphic {

    private:
        SDL_Window *_pWindow;
        SDL_Renderer *_pRenderer;
        bool _isOpen;

    public:
        SDL2_lib();
        ~SDL2_lib() override;

        //Window
        bool isWindowOpen() const override;
        void closeWindow() override;
        void clearWindow() override;

        //Event
        int getKeyEvent() override;

        //Display
        void displayWindow();
        void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
        void displayText(std::vector<std::shared_ptr<IText>> texts) override;
        void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
};
