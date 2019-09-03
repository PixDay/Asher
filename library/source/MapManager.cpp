/*
** Merline, 2019
** MapManager.cpp
** File description:
** Adrien Colombier
*/

#include "../include/MapManager.hpp"

MapManager::MapManager(ObjectManager &manager)
{
    sf::Vector2i position;
    size_t index = 0;

    for (size_t y = 0; y < 9; y++)
        for (size_t x = 0; x < 15; x++) {
            position.x = x * 128;
            position.y = y * 128 - 64;
            this->_tiles.push_back(new Tile());
            this->_tiles[index]->setPosition(position);
            index++;
        }
    for (auto tile : this->_tiles)
        manager.addObject(tile);
}