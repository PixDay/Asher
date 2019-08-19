/*
** EPITECH PROJECT, 2019
** Cursor.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/Cursor.hpp"

Cursor::Cursor() :
    _skin(11),
    _skins({"image/crosshair/crosshair001.png", "image/crosshair/crosshair002.png",
    "image/crosshair/crosshair003.png", "image/crosshair/crosshair004.png",
    "image/crosshair/crosshair005.png", "image/crosshair/crosshair006.png",
    "image/crosshair/crosshair007.png", "image/crosshair/crosshair008.png",
    "image/crosshair/crosshair009.png", "image/crosshair/crosshair010.png",
    "image/crosshair/crosshair011.png", "image/crosshair/crosshair012.png",
    "image/crosshair/crosshair013.png", "image/crosshair/crosshair014.png",
    "image/crosshair/crosshair015.png", "image/crosshair/crosshair016.png",
    "image/crosshair/crosshair017.png", "image/crosshair/crosshair018.png",
    "image/crosshair/crosshair019.png", "image/crosshair/crosshair020.png",
    "image/crosshair/crosshair021.png", "image/crosshair/crosshair022.png",
    "image/crosshair/crosshair023.png", "image/crosshair/crosshair024.png"})
{
    sf::Vector2f origin = {64.0f, 64.0f};
    sf::Vector2f scale = {0.525f, 0.525f};

    this->setTexture(this->_skins[this->_skin]);
    this->setOrigin(origin);
    this->setScale(scale);
    this->setDisplay(true);
}

void Cursor::draw()
{
}

void Cursor::autoManage()
{
}