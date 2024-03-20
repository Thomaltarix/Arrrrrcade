/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2
*/

#include <memory>
#include "sdl2.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDL2lib::SDL2lib()
{
    _Window = nullptr;
    _Renderer = nullptr;
    _isOpen = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw Error("SDL: Fail to init SDL");
    }

    if (SDL_CreateWindowAndRenderer(1920, 1080, SDL_WINDOW_SHOWN, &_Window, &_Renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());    
        SDL_Quit();
        throw Error("SDL: Fail to create window and renderer in SDL");
    }
    TTF_Init();
}

SDL2lib::~SDL2lib()
{
    SDL_DestroyRenderer(_Renderer);
    SDL_DestroyWindow(_Window);
    SDL_Quit();
}

//Window

bool SDL2lib::isWindowOpen() const
{
    return _isOpen;
}

void SDL2lib::closeWindow()
{
    _isOpen = false;
}

void SDL2lib::clearWindow()
{
    SDL_SetRenderDrawColor(_Renderer, 0, 0, 0, 255);
    SDL_RenderClear(_Renderer);
}

//Event

int SDL2lib::getKeyEvent()
{
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT)
            closeWindow();
        if (_event.type == SDL_KEYDOWN) {
            for (auto &mykey : _keyMap) {
                if (_event.key.keysym.sym == mykey.first)
                    return mykey.second;
            }
        }
        return -1;
    }
    return -1;
}

//Display

void SDL2lib::displayWindow()
{
    SDL_RenderPresent(_Renderer);
}

void SDL2lib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture = getEntityTexture(entity.get()->getPath());
        SDL_Rect dstrect = getRect(entity.get()->getPos(), entity.get()->getSize());
        SDL_RenderCopy(_Renderer, texture.get(), NULL, &dstrect);
    }
}

SDL_Rect SDL2lib::getRect(std::vector<std::size_t> pos, std::vector<std::size_t> size)
{
    if (pos.size() != 2 || size.size() != 2)
        throw Error("SDL: Error with size or position vectors");
    SDL_Rect rect = {(int)pos[0], (int)pos[1], (int)size[0], (int)size[1]};
    return rect;
}

std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> SDL2lib::getEntityTexture(std::string path)
{
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(IMG_Load((path + ".png").c_str()), SDL_FreeSurface);
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture(SDL_CreateTextureFromSurface(_Renderer, surface.get()), SDL_DestroyTexture);
    return texture;
}

void SDL2lib::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font = getFont(text.get()->getFontPath(), text.get()->getSize());
        SDL_Color color = { (Uint8)text.get()->getColor().get()->getR(),
                            (Uint8)text.get()->getColor().get()->getG(),
                            (Uint8)text.get()->getColor().get()->getB(),
                            (Uint8)text.get()->getColor().get()->getA()};
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(TTF_RenderText_Solid(font.get(), text.get()->getText().c_str(), color), SDL_FreeSurface);
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture(SDL_CreateTextureFromSurface(_Renderer, surface.get()), SDL_DestroyTexture);
        std::vector<size_t> size;
        size.push_back(text.get()->getText().length() * text.get()->getSize());
        size.push_back(text.get()->getSize());
        SDL_Rect dstrect = getRect(text.get()->getPos(), size);
        SDL_RenderCopy(_Renderer, texture.get(), NULL, &dstrect);
    }
}

std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> SDL2lib::getFont(std::string path, std::size_t size)
{
    std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font(TTF_OpenFont(path.c_str(), size), TTF_CloseFont);
    return font;
}

void SDL2lib::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void) sounds;
    return;
}
