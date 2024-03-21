/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Entity
*/

#pragma once

#include "../include/IEntity.hpp"

class Color: public virtual IColor {

    private:
        short _r;
        short _g;
        short _b;
        short _a;

    public:
        Color();
        ~Color() = default;

        //setter
        void setColor(short r, short g, short b, short a) override;

        //getters
        short getR() override;
        short getG() override;
        short getB() override;
        short getA() override;
};

class Entity : public virtual IEntity {
    
    private:
        std::vector<std::size_t> _pos;
        std::vector<std::size_t> _size;
        char _c;
        std::unique_ptr<IColor> _color;
        std::string _path;
        float _rotation;
    
    public:

        Entity();
        ~Entity() = default;

        //setters
        void setPos(std::size_t x, std::size_t y) override;
        void setSize(std::size_t x, std::size_t y) override;
        void setChar(char c) override;
        void setColor(std::unique_ptr<IColor> color) override;
        void setPath(const std::string &path) override;
        void setRotation(float rotation) override;

        //getters
        std::vector<std::size_t> getPos() const override;
        std::vector<std::size_t> getSize() const override;
        int getChar() const override;
        std::shared_ptr<IColor> getColor() const override;
        std::string getPath() const override;
        float getRotation() const override;
};
