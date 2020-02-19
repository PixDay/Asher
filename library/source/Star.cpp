/*
** Merline, 2020
** Star.cpp
** File description:
** Adrien Colombier
*/

#include "../include/Star.hpp"

Star::Star():
    _skins({"image/background/star_01.png", "image/background/star_02.png",
            "image/background/star_03.png", "image/background/star_04.png",
            "image/background/star_05.png", "image/background/star_06.png"})
{
    sf::Vector2f scale = {0.15f, 0.15f};
    sf::Vector2f pos = {2000.0f, 0.0f};
    sf::Vector2f origin = {64.0f, 64.0f};
    _rotation = (float)(std::rand() % 5 - 10);
    pos.y = (float)(std::rand() % 1000);
    this->setSpeed((float)((std::rand() % 20) + 1));
    this->setPosition(pos);
    this->setScale(scale);
    this->setOrigin(origin);
    this->setTexture(_skins[std::rand() % 6]);
    this->setDisplay(true);
}

void Star::draw()
{
}

void Star::autoManage()
{
    sf::Vector2f position = this->getPosition();

    this->setAngle(this->getAngle() + this->_rotation);
    position.x -= _speed;
    if (position.x < -10.0f) {
        position.y = (float)(std::rand() % 1000);
        position.x = 1920.0f;
        this->setAngle(0.0f);
    }
    this->setPosition(position);
}