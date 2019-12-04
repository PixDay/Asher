/*
** Merline, 2019
** BlackHole.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class BlackHole : public Object 
{
    public:
        BlackHole();
        ~BlackHole() = default;

        void draw();
        void autoManage();
    private:
        const std::string _texture;
};