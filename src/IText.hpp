/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IText
*/

#pragma once

#include <string>
#include <vector>

#include "IEntity.hpp"

class IText {
    public:
        IText() = default;
        virtual ~IText() = default;

        //setters
        virtual void setFontPath(const std::string &fontPath) = 0;
        virtual void setText(const std::string &text) = 0;
        virtual void setColor(std::unique_ptr<IColor> color) = 0;
        virtual void setPos(std::size_t x, std::size_t y) = 0;
        virtual void setSize(std::size_t x, std::size_t y) = 0;
        virtual void setRotation(float rotation) = 0;

        //getters
        virtual std::string getFontPath() = 0;
        virtual std::string getText() = 0;
        virtual std::shared_ptr<IColor> getColor() const = 0;
        virtual std::vector<std::size_t> getPos() const = 0;
        virtual std::vector<std::size_t> getSize() const = 0;
        virtual float getRotation() const = 0;
};

class Text : public Text {
    public:
        Text();
        ~Text();

        //setters
        void setFontPath(const std::string &fontPath);
        void setText(const std::string &text);
        void setColor(std::unique_ptr<IColor> color);
        void setPos(std::size_t x, std::size_t y);
        void setSize(std::size_t x, std::size_t y);
        void setRotation(float rotation);

        //getters
        std::string getFontPath();
        std::string getText();
        std::shared_ptr<IColor> getColor();
        std::vector<std::size_t> getPos();
        std::vector<std::size_t> getSize();
        float getRotation();

    private:
        std::string _fontPath;
        std::string _text;
        std::unique_ptr<IColor> _color;
        std::vector<std::size_t> _size;
        std::vector<std::size_t> _pos;
        float _rotation;
};
