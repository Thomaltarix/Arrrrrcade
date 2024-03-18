/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2
*/

#include <memory>
#include "sdl2.hpp"

SDL2lib::SDL2lib()
{
    _Window = nullptr;
    _Renderer = nullptr;
    _isOpen = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw Error("Fail to init SDL");
    }

    if (SDL_CreateWindowAndRenderer(1920, 1080, SDL_WINDOW_SHOWN, &_Window, &_Renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());    
        SDL_Quit();
        throw Error("Fail to create window and renderer in SDL");
    }
}

SDL2lib::~SDL2lib()
{
    SDL_Quit();
}

//Window

bool SDL2lib::isWindowOpen() const
{
    return _isOpen;
}

void SDL2lib::closeWindow()
{
}

void SDL2lib::clearWindow()
{
}

//Event

int SDL2lib::getKeyEvent()
{
    return 0;
}

//Display

void SDL2lib::displayWindow()
{
    SDL_RenderPresent(_Renderer);
}

void SDL2lib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    (void) entities;
}

void SDL2lib::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    (void) texts;
}

void SDL2lib::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void) sounds;
}
