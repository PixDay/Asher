/*
** EPITECH PROJECT, 2019
** player.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "Player.hpp"

Player::Player() : 
    _skins({"image/skin/defaultSkin.png", 
    "image/skin/negatifSkin.png", "image/skin/blueSkin.png",
    "image/skin/cyanSkin.png", "image/skin/greenSkin.png",
    "image/skin/jauneSkin.png", "image/skin/magentaSkin.png",
    "image/skin/redSkin.png", "image/skin/negatifBlueSkin.png",
    "image/skin/negatifCyanSkin.png", "image/skin/negatifGreenSkin.png",
    "image/skin/negatifJauneSkin.png", "image/skin/negatifMagentaSkin.png",
    "image/skin/negatifRedSkin.png"})
{
    sf::Vector2f origin = {150.0f, 150.0f};
    sf::Vector2f position = {200.0f, 200.0f};
    sf::Vector2f scale = {0.2f, 0.2f};

    this->setPosition(position);
    this->setTexture(this->_skins[0]);
    this->setOrigin(origin);
    this->setScale(scale);
}

void Player::draw()
{
    std::cout << "drawing player" << std::endl;
}

void Player::autoManage()
{
    std::cout << "player brain" << std::endl;
}