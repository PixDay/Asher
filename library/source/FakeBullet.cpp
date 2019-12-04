/*
** EPITECH PROJECT, 2019
** FakeBullet.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/FakeBullet.hpp"

FakeBullet::FakeBullet():
_skins({"image/shot/shotThin.png", "image/shot/shotLarge.png",
    "image/shot/shotOrange.png", "image/shot/shotRed.png"})
{
    sf::Vector2f scale = {0.4f, 0.4f};

    this->setTexture(this->_skins[3]);
    this->setScale(scale);
    this->setDisplay(true);
}

void FakeBullet::draw()
{
}

void FakeBullet::autoManage()
{
}

void FakeBullet::setSkin(size_t skin)
{
    this->setTexture(this->_skins[skin]);
}