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
#include "ObjectManager.hpp"
#include "Tile.hpp"

/* CLASS */

class MapManager
{
    public:
        MapManager(ObjectManager &manager);
        ~MapManager() = default;
    private:
        std::vector<Tile *> _tiles;
};