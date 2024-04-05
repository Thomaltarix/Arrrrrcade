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
#include <unordered_map>

namespace Arcade {
    class SDL2lib : public AGraphic {

        private:
            SDL_Window *_Window;
            SDL_Renderer *_Renderer;
            SDL_Event _event;
            bool _isOpen;

            SDL_Rect getRect(std::vector<std::size_t> pos, std::vector<std::size_t> size);
            std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> getEntityTexture(std::string path);
            std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> getFont(std::string path, std::size_t size);

            int _mouseX;
            int _mouseY;

            const std::unordered_map<SDL_KeyCode, int> _keyMap = {
                {SDLK_a, 0},
                {SDLK_b, 1},
                {SDLK_c, 2},
                {SDLK_d, 3},
                {SDLK_e, 4},
                {SDLK_f, 5},
                {SDLK_g, 6},
                {SDLK_h, 7},
                {SDLK_i, 8},
                {SDLK_j, 9},
                {SDLK_k, 10},
                {SDLK_l, 11},
                {SDLK_m, 12},
                {SDLK_n, 13},
                {SDLK_o, 14},
                {SDLK_p, 15},
                {SDLK_q, 16},
                {SDLK_r, 17},
                {SDLK_s, 18},
                {SDLK_t, 19},
                {SDLK_u, 20},
                {SDLK_v, 21},
                {SDLK_w, 22},
                {SDLK_x, 23},
                {SDLK_y, 24},
                {SDLK_z, 25},
                {SDLK_ESCAPE, 26},
                {SDLK_TAB, 27},
                {SDLK_LSHIFT, 28},
                {SDLK_LCTRL, 29},
                {SDLK_SPACE, 30},
                {SDLK_RETURN, 31},
                {SDLK_BACKSPACE, 32},
                {SDLK_UP, 33},
                {SDLK_DOWN, 34},
                {SDLK_LEFT, 35},
                {SDLK_RIGHT, 36},
                {SDLK_0, 37},
                {SDLK_1, 38},
                {SDLK_2, 39},
                {SDLK_3, 40},
                {SDLK_4, 41},
                {SDLK_5, 42},
                {SDLK_6, 43},
                {SDLK_7, 44},
                {SDLK_8, 45},
                {SDLK_9, 46}
            };

        public:
            SDL2lib();
            ~SDL2lib() override;

            //Window
            bool isWindowOpen() const override;
            void closeWindow() override;
            void clearWindow() override;

            //Event
            int getKeyEvent() override;
            std::pair<int, int> getMousePosition() override;

            //Display
            void displayWindow();
            void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) override;
            void displayText(std::vector<std::shared_ptr<IText>> texts) override;
            void playSound(std::vector<std::shared_ptr<ISound>> sounds) override;
    };
}
