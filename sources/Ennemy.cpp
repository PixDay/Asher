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

    this->setPosition(position);
    this->setDisplay(true);
    this->setScale(scale);
    this->setOrigin(origin);
    this->setTexture("image/ennemy/ennemy.png");
}

void Ennemy::draw()
{
}

void Ennemy::autoManage()
{
    if (this->getPosition().x < 0 && this->getPosition().y < 0)
        this->setDisplay(false);
    else
        this->setDisplay(true);
}