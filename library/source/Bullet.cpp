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
    _distance(400.0f),
    _range(400.0f),
    _skin(1),
    _skins({"image/shot/shotThin.png", "image/shot/shotLarge.png",
    "image/shot/shotOrange.png", "image/shot/shotRed.png"})
{
    sf::Vector2f scale = {0.4f, 0.4f};

    this->setTexture(this->_skins[this->_skin]);
    this->setScale(scale);
    this->setDisplay(false);
    this->setSpeed(15.0f);
}

void Bullet::draw()
{
}

void Bullet::autoManage()
{
    sf::Vector2f tmp = this->getPosition();

    tmp.x += this->_direction.x;
    tmp.y += this->_direction.y;
    this->_distance = this->_distance - (std::sqrt(this->_direction.x * this->_direction.x + this->_direction.y * this->_direction.y));
    if (this->_distance <= 0.0f) {
        this->setDisplay(false);
        this->_distance = this->_range;
        this->_direction.x = 0.0f;
        this->_direction.y = 0.0f;
    }
    this->setPosition(tmp);
}

void Bullet::setDirection(sf::Vector2f const &direction)
{
    this->_direction = direction;
}

void Bullet::setSkin(size_t skin)
{
    this->_skin = skin;
    this->setTexture(this->_skins[this->_skin]);
}

size_t Bullet::getSkin() const
{
    return this->_skin;
}

void Bullet::setRange(float range)
{
    this->_range = range;
}

void Bullet::setDistance(float distance)
{
    this->_distance = distance;
}