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
    _distance(500.0f),
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
    sf::Vector2f tmp = this->getPosition();

    tmp.x += this->_direction.x;
    tmp.y += this->_direction.y;
    this->setPosition(tmp);
}

void Bullet::setDirection(sf::Vector2f const &direction)
{
    this->_direction = direction;
}