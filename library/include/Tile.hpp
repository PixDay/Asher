/*
** Merline, 2019
** Tile.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class Tile: public Object 
{
    public:
        Tile();
        ~Tile() = default;

        void draw();
        void autoManage();
};