/*
** EPITECH PROJECT, 2024
** Arrrrrcade
** File description:
** Sound
*/

#pragma once

#include "../include/ISound.hpp"

namespace Arcade {
    namespace Menu {
        class Sound : public ISound {
            public:
                Sound();
                ~Sound();

                //setters
                void setPathSound(const std::string &pathSound) override;
                void setVolume(float volume) override;
                void setStatus(int status) override;

                //getters
                std::string getPathSound() override;
                float getVolume() const override;
                int getStatus() const override;
            private:
                std::string _pathSound;
                float _volume;
                int _status;
        };
    }
}
