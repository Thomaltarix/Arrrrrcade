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



class DLLoader {

    private:
        void *_handle;

    public:

        DLLoader();
        ~DLLoader();

        void load(const std::string &libso);

        template<typename T>
        std::unique_ptr<T> getInstance(const std::string &function)
        {
            std::function<std::unique_ptr<T>()> sym;

            sym = (std::unique_ptr<T>(*)())dlsym(_handle, function);
            if (!sym) {
                printf("%s\n", dlerror());
                return nullptr;
            }
            return sym();
        }
};
