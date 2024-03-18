/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** IEntity
*/

#pragma once

#include <string>
#include <memory>
#include <vector>

class IColor {
    public:
        virtual ~IColor() = default;

        //setter
        virtual void setColor(short r, short g, short b, short a) = 0;

        //getters
        virtual short getR() = 0;
        virtual short getG() = 0;
        virtual short getB() = 0;
        virtual short getA() = 0;
};

class IEntity {
    public:
        virtual ~IEntity() = default;

        //setters
        virtual void setPos(std::size_t x, std::size_t y) = 0;
        virtual void setSize(std::size_t x, std::size_t y) = 0;
        virtual void setChar(char c) = 0;
        virtual void setColor(std::unique_ptr<IColor> color) = 0;
        virtual void setPath(const std::string &path) = 0;
        virtual void setRotation(float rotation) = 0;

        //getters
        virtual std::vector<std::size_t> getPos() const = 0;
        virtual std::vector<std::size_t> getSize() const = 0;
        virtual int getChar() const = 0;
        virtual std::shared_ptr<IColor> getColor() const = 0;
        virtual std::string getPath() const = 0;
        virtual float getRotation() const = 0;
};
