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
#include "Keys.hpp"

Arcade::SDL2lib::SDL2lib()
{
    _Window = nullptr;
    _Renderer = nullptr;
    _isOpen = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw Error("SDL: Fail to init SDL");
    }

    if (SDL_CreateWindowAndRenderer(725, 899, SDL_WINDOW_SHOWN, &_Window, &_Renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());    
        SDL_Quit();
        throw Error("SDL: Fail to create window and renderer in SDL");
    }
    TTF_Init();
}

Arcade::SDL2lib::~SDL2lib()
{
    SDL_DestroyRenderer(_Renderer);
    SDL_DestroyWindow(_Window);
    SDL_Quit();
}

//Window

bool Arcade::SDL2lib::isWindowOpen() const
{
    return _isOpen;
}

void Arcade::SDL2lib::closeWindow()
{
    _isOpen = false;
}

void Arcade::SDL2lib::clearWindow()
{
    SDL_SetRenderDrawColor(_Renderer, 0, 0, 0, 255);
    SDL_RenderClear(_Renderer);
}

//Event

int Arcade::SDL2lib::getKeyEvent()
{
    while (SDL_PollEvent(&_event)) {

        switch (_event.type)
        {
            case SDL_QUIT:
                closeWindow();
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (_event.button.button == SDL_BUTTON_LEFT)
                        return MOUSE_LEFT;
                if (_event.button.button == SDL_BUTTON_RIGHT)
                        return MOUSE_RIGHT;
                break;

            case SDL_KEYDOWN:
                for (auto &mykey : _keyMap) {
                    if (_event.key.keysym.sym == mykey.first)
                        return mykey.second;
                }
                break;
            default:
                return -1;
        }
    }
    return -1;
}

std::pair<int, int> Arcade::SDL2lib::getMousePosition()
{
    _mouseX = _event.motion.x;
    _mouseY = _event.motion.y;
    return std::make_pair<int, int>(_mouseX / 29, _mouseY / 29);
}

//Display

void Arcade::SDL2lib::displayWindow()
{
    SDL_RenderPresent(_Renderer);
}

void Arcade::SDL2lib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities) {
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture = getEntityTexture(entity.get()->getPath());
        SDL_Rect dstrect = getRect(entity.get()->getPos(), entity.get()->getSize());
        SDL_Point center = {(int)(entity->getSize()[0] / 2), (int)(entity->getSize()[1] / 2)};
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        SDL_RenderCopyEx(_Renderer,
                   texture.get(),
                   NULL,
                   &dstrect,
                   entity->getRotation(),
                   &center,
                   flip);
    }
}

SDL_Rect Arcade::SDL2lib::getRect(std::vector<std::size_t> pos, std::vector<std::size_t> size)
{
    if (pos.size() != 2 || size.size() != 2)
        throw Error("SDL: Error with size or position vectors");
    SDL_Rect rect = {(int)pos[0] * 29, (int)pos[1] * 29, (int)size[0], (int)size[1]};
    return rect;
}

std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> Arcade::SDL2lib::getEntityTexture(std::string path)
{
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(IMG_Load((path + ".png").c_str()), SDL_FreeSurface);
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture(SDL_CreateTextureFromSurface(_Renderer, surface.get()), SDL_DestroyTexture);
    return texture;
}

void Arcade::SDL2lib::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts) {
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font = getFont(text->getFontPath() + ".ttf", text->getSize());
        SDL_Color color = { (Uint8)text->getColor()->getR(),
                            (Uint8)text->getColor()->getG(),
                            (Uint8)text->getColor()->getB(),
                            (Uint8)text->getColor()->getA()};
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(TTF_RenderText_Solid(font.get(), text->getText().c_str(), color), SDL_FreeSurface);
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture(SDL_CreateTextureFromSurface(_Renderer, surface.get()), SDL_DestroyTexture);
        std::vector<size_t> size;
        size.push_back(text->getText().length() * (text->getSize() - 10));
        size.push_back(text->getSize());
        SDL_Rect dstrect = getRect(text->getPos(), size);
        SDL_RenderCopy(_Renderer, texture.get(), NULL, &dstrect);
    }
}

std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> Arcade::SDL2lib::getFont(std::string path, std::size_t size)
{
    std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font(TTF_OpenFont(path.c_str(), size), TTF_CloseFont);
    return font;
}

void Arcade::SDL2lib::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    (void) sounds;
    return;
}
