/*
** EPITECH PROJECT, 2019
** Bullet.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/Glow.hpp"

Glow::Glow()
{
    sf::Vector2f scale = {0.2f, 0.2f};
    sf::Vector2f origin = {150.0f, 150.0f};

    this->setTexture("image/skin/glowSkin.png");
    this->setDisplay(true);
    this->setScale(scale);
    this->setOrigin(origin);
}

void Glow::draw()
{
}

void Glow::autoManage()
{
}