/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGraphic
*/

#pragma once

#include "IGraphic.hpp"
#include <memory>

namespace Arcade {
    class AGraphic : public virtual IGraphic{
        public:
            virtual ~AGraphic() = default;

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

            class Error : public std::exception {
                public:

                    Error(const std::string& msg)
                    {
                        _msg = msg;
                    };

                    const char* what() const noexcept override
                    {
                        return _msg.c_str();
                    };

                private:
                    std::string _msg;
            };
    };
}