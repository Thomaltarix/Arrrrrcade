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
        IColor() = default;
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
        IEntity() = default;
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

class Color : public IColor {

    public:
        Color();
        ~Color() = default;

        //setters
        void setColor(short r, short g, short b, short a) override;

        //getters
        short getR() override;
        short getG() override;
        short getB() override;
        short getA() override;

    private:
        short _r;
        short _g;
        short _b;
        short _a;
};

class Entity : public IEntity {
    public:
        Entity();
        ~Entity();

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

    private:
        std::vector<std::size_t> _pos;
        std::vector<std::size_t> _size;
        char _character;
        std::unique_ptr<IColor> _color;
        std::string _path;
        float _rotate;
};
