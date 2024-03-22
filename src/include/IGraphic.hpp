/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphic
*/

#pragma once

#include "IEntity.hpp"
#include "IText.hpp"
#include "ISound.hpp"
#include <memory>

namespace Arcade {
    class IGraphic {
        public:
            virtual ~IGraphic() = default;

            //Window
            virtual bool isWindowOpen() const = 0;
            virtual void closeWindow() = 0;
            virtual void clearWindow() = 0;

            //Event
            virtual int getKeyEvent() = 0;

            //Display
            virtual void displayWindow() = 0;
            virtual void displayEntities(std::vector<std::shared_ptr<IEntity>> entities) = 0;
            virtual void displayText(std::vector<std::shared_ptr<IText>> texts) = 0;
            virtual void playSound(std::vector<std::shared_ptr<ISound>> sounds) = 0;
    };
}
