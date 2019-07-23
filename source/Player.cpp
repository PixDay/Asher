/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "Player.hpp"

Player::Player(ObjectManager &manager) :
    _skin(0),
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
    this->setTexture(this->_skins[13]);
    this->setOrigin(origin);
    this->setScale(scale);
    this->setSpeed(1.5f);
    this->_cursor = new Cursor();
    this->_window = manager.getWindow();
    manager.addObject(this->_cursor);
}

void Player::draw()
{
}

void Player::autoManage()
{
    this->updateMove();
    this->updateCursor();
    this->setAngle(this->_cursor->getPosition());
}

void Player::updateCursor()
{
    this->_cursor->setPosition(this->_mouse.getPosition(*this->_window));
}

void Player::updateMove()
{
    sf::Vector2f position = this->getPosition();

    if (this->_moveClock.getElapsedTime().asSeconds() >= 0.01f) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            position.x = position.x - this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            position.x = position.x + this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            position.y += this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            position.y -= this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
    }
}