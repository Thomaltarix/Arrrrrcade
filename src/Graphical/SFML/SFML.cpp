/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml
*/

#include "SFML.hpp"

Arcade::SFMLlib::SFMLlib()
{
    _window.create(sf::VideoMode(725, 899), "Arcade", sf::Style::Close);
    if (!isWindowOpen())
        throw Error("SFML: Failed to create window");

    _event = sf::Event();
}

Arcade::SFMLlib::~SFMLlib()
{
    closeWindow();
}

// ------------------ WINDOW ------------------ //

bool Arcade::SFMLlib::isWindowOpen() const
{
    return _window.isOpen();
}

void Arcade::SFMLlib::closeWindow()
{
    _window.close();
    if (isWindowOpen())
        throw Error("SFML: Failed to close window");
}

void Arcade::SFMLlib::clearWindow()
{
    _window.clear();
}

// ------------------ EVENT ------------------ //

int Arcade::SFMLlib::getKeyEvent()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            closeWindow();
        if (_event.type == sf::Event::KeyPressed) {
            for (auto &key : _keyMap) {
                if (_event.key.code == key.first)
                    return key.second;
            }
            if (_event.key.code == 51)
                return 41;
        }
        return -1;
    }
    return -1;
}

// ------------------ DISPLAY ------------------ //

void Arcade::SFMLlib::displayWindow()
{
    _window.display();
}

void Arcade::SFMLlib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities)
        _window.draw(getSprite(entity));
}

void Arcade::SFMLlib::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts)
        _window.draw(createText(text));
}

void Arcade::SFMLlib::playSound(std::vector<std::shared_ptr<ISound>> sounds)
{
    for (auto &sound : sounds) {
        switch (sound->getStatus()) {
            case ISound::Status::START:
                playSound(sound, false);
                break;
            case ISound::Status::LOOP:
                playSound(sound, true);
                break;
            case ISound::Status::STOP:
                _sounds[sound->getPathSound()].stop();
                break;
            case ISound::Status::DONE:
                break;
        }
    }
}

// ------------------ PRIVATE ------------------ //

sf::RectangleShape Arcade::SFMLlib::getSprite(std::shared_ptr<IEntity> entity)
{
    sf::RectangleShape shape(sf::Vector2f(entity->getSize()[0], entity->getSize()[1]));
    std::string path = entity->getPath();

    if (_textures.find(path) == _textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(path + ".png")) {
            return shape;
        }
        _textures[path] = texture;
    }
    shape.setOrigin(entity->getSize()[0] / 2, entity->getSize()[1] / 2);
    shape.setTexture(&_textures[path]);
    shape.setRotation(entity->getRotation());
    shape.setPosition((entity->getPos()[0] * 29) + entity->getSize()[0] / 2, (entity->getPos()[1] * 29) + entity->getSize()[1] / 2);
    return shape;
}

sf::Text Arcade::SFMLlib::createText(std::shared_ptr<IText> text)
{
    sf::Text sfText;
    sf::Color color;
    std::string path = text->getFontPath();

    if (_fonts.find(path) == _fonts.end()) {
        sf::Font font;
        if (!font.loadFromFile(path + ".ttf"))
            return sfText;
        _fonts[path] = font;
    }
    sfText.setFont(_fonts[path]);
    sfText.setString(text->getText());
    sfText.setCharacterSize(text->getSize());
    color = sf::Color(text->getColor()->getR(),
                    text->getColor()->getG(),
                    text->getColor()->getB(),
                    text->getColor()->getA());
    sfText.setFillColor(color);
    sfText.setPosition(text->getPos()[0] * 29, text->getPos()[1] * 29);
    return sfText;
}

void Arcade::SFMLlib::playSound(std::shared_ptr<ISound> sound, bool loop)
{
    std::string path = sound->getPathSound();

    if (_soundBuffers.find(path) == _soundBuffers.end()) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(path + ".mp3"))
            return;
        _soundBuffers[path] = buffer;
    }
    _sounds[path].setBuffer(_soundBuffers[path]);
    _sounds[path].setLoop(loop);
    _sounds[path].play();
}
