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
    sf::Vector2f scale = {0.25f, 0.25f};
    sf::Vector2f origin = {150.0f, 150.0f};
    sf::Vector2f position = {-100.0f, 0.0f};

    this->setTexture("image/skin/glowSkin.png");
    this->setDisplay(true);
    this->setScale(scale);
    this->setOrigin(origin);
    this->setPosition(position);
}

void Glow::draw()
{
}

void Glow::autoManage()
{
}

void Glow::swapSkin(bool state)
{
    if (state)
        this->setTexture("image/skin/glowSkinSpeed.png");
    else
        this->setTexture("image/skin/glowSkin.png");
}