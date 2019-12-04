/*
** Merline, 2019
** Icon.cpp
** File description:
** Thomas Daullé
*/

#include "../include/Icon.hpp"

Icon::Icon(std::string path)
{
    sf::Vector2f position = {0, 0};

    this->setTexture(path);
    this->setPosition(position);
    this->setDisplay(true);
}

void Icon::draw()
{}

void Icon::autoManage()
{}