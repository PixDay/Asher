/*
** Merline, 2019
** Bullet.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class Glow : public Object 
{
    public:
        Glow();
        ~Glow() = default;

        void draw();
        void autoManage();
};