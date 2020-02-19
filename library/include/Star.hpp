/*
** Merline, 2020
** Star.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class Star: public Object 
{
    public:
        Star();
        ~Star() = default;

        void draw();
        void autoManage();
    private:
        std::vector<std::string> _skins;
        float _rotation;
};