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
    std::srand(std::time(nullptr));
    for (size_t y = 0; y < 9; y++) {
        for (size_t x = 0; x < 15; x++) {
            position.x = x * 128;
            position.y = y * 128 - 64;
            this->_tiles.push_back(new Tile());
            this->_stars.push_back(new Star());
            this->_tiles[index]->setPosition(position);
            index++;
        }
    }
    for (auto tile : this->_tiles)
        manager.addObject(tile);
    for (auto star : this->_stars)
        manager.addObject(star);
}