/*
** Merline, 2019
** Player.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */
#include "Object.hpp"

class Player : public Object
{
    public:
        Player();
        ~Player() = default;

        void draw();
};