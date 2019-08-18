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
    "image/skin/negatifRedSkin.png"}),
    _shoot(30),
    _currentBullet(0)
{
    sf::Vector2f origin = {150.0f, 150.0f};
    sf::Vector2f position = {200.0f, 200.0f};
    sf::Vector2f scale = {0.2f, 0.2f};

    this->setPosition(position);
    this->setTexture(this->_skins[this->_skin]);
    this->setOrigin(origin);
    this->setScale(scale);
    this->setSpeed(3.5f);
    this->setDisplay(true);
    this->_cursor = new Cursor();
    this->_window = manager.getWindow();
    manager.addObject(this->_cursor);
    for (size_t bullet_number = 0; bullet_number < this->_shoot; bullet_number++)
        this->_bullets.push_back(new Bullet());
    for (auto bullet : this->_bullets)
        manager.addObject(bullet);
}

void Player::draw()
{
}

void Player::autoManage()
{
    this->updateMove();
    this->updateCursor();
    this->setAngle(this->_cursor->getPosition());
    this->_bullets[this->_currentBullet]->setAngle(this->getAngle());
    this->_bullets[this->_currentBullet]->setDisplay(true);
    this->_bullets[this->_currentBullet]->setPosition(this->getPosition());
}

void Player::updateCursor()
{
    this->_cursor->setPosition(this->_mouse.getPosition(*this->_window));
}

void Player::updateMove()
{
    sf::Vector2f position = this->getPosition();

    if (this->_moveClock.getElapsedTime().asSeconds() >= 0.008f) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            position.x = position.x - this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            position.x = position.x + this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            position.y += this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            position.y -= this->getSpeed();
            this->setPosition(position);
            this->_moveClock.restart();
        }
    }
}