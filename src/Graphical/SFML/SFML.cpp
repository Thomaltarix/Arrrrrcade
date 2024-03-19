/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml
*/

#include "SFML.hpp"

SFMLlib::SFMLlib()
{
    if (isWindowOpen())
        closeWindow();
    _window.create(sf::VideoMode(1920, 1080), "Arcade", sf::Style::Close);
    _window.setFramerateLimit(60);
    if (!isWindowOpen())
        throw Error("SFML: Failed to create window");

    _event = sf::Event();
}

SFMLlib::~SFMLlib()
{
    closeWindow();
}

// ------------------ WINDOW ------------------ //

bool SFMLlib::isWindowOpen() const
{
    return _window.isOpen();
}

void SFMLlib::closeWindow()
{
    _window.close();
    if (isWindowOpen())
        throw Error("SFML: Failed to close window");
}

void SFMLlib::clearWindow()
{
    _window.clear();
}

// ------------------ EVENT ------------------ //

int SFMLlib::getKeyEvent()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            closeWindow();
        if (_event.type == sf::Event::KeyPressed) {
            for (auto &key : _keyMap) {
                if (_event.key.code == key.first)
                    return key.second;
            }
        }
        return -1;
    }
    return -1;
}

// ------------------ DISPLAY ------------------ //

void SFMLlib::displayWindow()
{
    _window.display();
}

void SFMLlib::displayEntities(std::vector<std::shared_ptr<IEntity>> entities)
{
    for (auto &entity : entities)
        _window.draw(createSprite(entity));
}

void SFMLlib::displayText(std::vector<std::shared_ptr<IText>> texts)
{
    for (auto &text : texts)
        _window.draw(createText(text));
}

void SFMLlib::playSound(std::vector<std::shared_ptr<ISound>> sounds)
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

sf::Sprite SFMLlib::createSprite(std::shared_ptr<IEntity> entity)
{
    sf::Sprite sprite;

    if (_textures.find(entity->getPath()) == _textures.end()) {
        sf::Texture texture;
        if (!texture.loadFromFile(entity->getPath() + ".png"))
            throw Error("SFML: Failed to load texture");
        _textures[entity->getPath()] = texture;
    }
    sprite.setTexture(_textures[entity->getPath()]);
    sprite.setPosition(entity->getPos()[0], entity->getPos()[1]);
    sprite.setScale(entity->getSize()[0], entity->getSize()[1]);
    sprite.setRotation(entity->getRotation());
    return sprite;
}

sf::Text SFMLlib::createText(std::shared_ptr<IText> text)
{
    sf::Text sfText;
    sf::Color color;
    std::string path = text->getFontPath();

    if (_fonts.find(path) == _fonts.end()) {
        sf::Font font;
        if (!font.loadFromFile(path + ".ttf"))
            throw Error("SFML: Failed to load font");
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
    sfText.setPosition(text->getPos()[0], text->getPos()[1]);
    return sfText;
}

void SFMLlib::playSound(std::shared_ptr<ISound> sound, bool loop)
{
    std::string path = sound->getPathSound();

    if (_soundBuffers.find(path) == _soundBuffers.end()) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(path + ".mp3"))
            throw Error("SFML: Failed to load sound");
        _soundBuffers[path] = buffer;
    }
    _sounds[path].setBuffer(_soundBuffers[path]);
    _sounds[path].setLoop(loop);
    _sounds[path].play();
}
