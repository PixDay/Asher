/*
** Merline, 2019
** Ennemy.cpp
** File description:
** Adrien Colombier
*/

#include "Ennemy.hpp"

Ennemy::Ennemy()
{
    sf::Vector2f position = {100.0f, 100.0f};
    sf::Vector2f scale = {0.5f, -0.5f};
    sf::Vector2f origin = {64.0f, 71.0f};

    int random = std::rand() % 2;
    position.x = 1920 + (std::rand() % 400);
    position.y = 0 - (std::rand() % 400);
    if (random) {
        position.y = 1080 + (std::rand() % 400);
        position.x = 0 - (std::rand() % 400);
    }
    this->setPosition(position);
    this->setDisplay(true);
    this->setScale(scale);
    this->setOrigin(origin);
    this->setTexture("image/ennemy/ennemy.png");
    this->setSpeed((float)(std::rand() % 8000) / 5000.0f + 1.0f);
}

void Ennemy::draw()
{
}

void Ennemy::autoManage()
{
    if (this->getPosition().x < 0 && this->getPosition().y < 0)
        this->setDisplay(false);
    else {
        this->setDisplay(true);
        sf::Vector2f position = this->getPosition();
        position.x = (position.x > _target.x) ? position.x + -1 * this->getSpeed() : position.x + 1 * this->getSpeed();
        position.y = (position.y > _target.y) ? position.y + -1 * this->getSpeed() : position.y + 1 * this->getSpeed();
        position.x = (std::abs(position.x - _target.x) <= (this->getSpeed())) ? _target.x : position.x; 
        position.y = (std::abs(position.y - _target.y) <= (this->getSpeed())) ? _target.y : position.y; 
        this->setPosition(position);
    }
}