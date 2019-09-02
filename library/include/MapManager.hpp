/*
** Merline, 2019
** MapManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include <vector>
#include "Object.hpp"

/* CLASS */

class MapManager
{
    public:
        MapManager();
        ~MapManager() = default;

    private:
        std::vector<Object *> _tiles;
};