/*
** EPITECH PROJECT, 2019
** Friend.cpp
** File description:
** Adrien Colombier
*/

#include "Friend.hpp"

Friend::Friend()
{
    sf::Vector2f origin = {150.0f, 150.0f};
    sf::Vector2f position = {200.0f, 200.0f};
    sf::Vector2f scale = {0.25f, 0.25f};

    this->setPosition(position);
    this->setTexture("image/skin/negatifGreenSkin.png");
    this->setOrigin(origin);
    this->setScale(scale);
    this->setPosition(position);
    this->setDisplay(true);
    
    for (size_t bullet_number = 0; bullet_number < 20; bullet_number++)
        this->_bullets.push_back(new FakeBullet());
}

void Friend::draw()
{
}

void Friend::autoManage()
{
}