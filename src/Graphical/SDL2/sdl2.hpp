/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2
*/

#pragma once

#include "AGraphic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class SDL2lib : public AGraphic {

    private:
        SDL_Window *_Window;
        SDL_Renderer *_Renderer;
        bool _isOpen;

        SDL_Rect getRect(std::vector<std::size_t> pos, std::vector<std::size_t> size);
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> getEntityTexture(std::string path);
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> getFont(std::string path, std::size_t size);

    public:
        SDL2lib();
        ~SDL2lib() override;

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
