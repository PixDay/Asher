/*
** EPITECH PROJECT, 2019
** BlackHole.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/BlackHole.hpp"

BlackHole::BlackHole() :
    _texture("image/blackhole/blackhole-icon.png")
{
    sf::Vector2f origin = {128.0f, 128.0f};
    sf::Vector2f scale = {0.12f, 0.12f};

    this->setTexture(this->_texture);
    this->setOrigin(origin);
    this->setScale(scale);
    this->setDisplay(false);
}

void BlackHole::draw()
{
}

void BlackHole::autoManage()
{
}