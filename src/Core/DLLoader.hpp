/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader
*/

#pragma once

#include <memory>
#include <dlfcn.h>
#include <functional>

namespace Arcade {
    class DLLoader {

        private:
            void *_handle;

        public:

            DLLoader();
            ~DLLoader();

            void load(const std::string &libso);

            template<typename T>
            T *getInstance(const std::string &function)
            {
                T *(*sym)(void);

                sym = (T *(*)())dlsym(_handle, function.c_str());
                if (!sym) {
                    return nullptr;
                }
                return sym();
            }
    };
}
