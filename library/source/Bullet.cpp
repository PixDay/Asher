/*
** EPITECH PROJECT, 2019
** Bullet.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/Bullet.hpp"

Bullet::Bullet() :
    _direction({0.0f, 0.0f}),
    _distance(0.0f),
    _skin(0),
    _skins({"image/shot/shotThin.png", "image/shot/shotLarge.png",
    "image/shot/shotOrange.png", "image/shot/shotRed.png"})
{
    //sf::Vector2f origin = {64.0f, 64.0f};
    sf::Vector2f scale = {0.4f, 0.4f};

    this->setTexture(this->_skins[this->_skin]);
    //this->setOrigin(origin);
    this->setScale(scale);
    this->setDisplay(false);
}

void Bullet::draw()
{
}

void Bullet::autoManage()
{
}