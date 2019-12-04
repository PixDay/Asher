/*
** Merline, 2019
** Button.cpp
** File description:
** Thomas Daullé
*/

#include "../include/Button.hpp"

Button::Button(std::string const &path, sf::Vector2f position, sf::Vector2f scale, sf::IntRect hitbox)
{
    this->setTexture(path);
    _textureButton = path;

    this->setPosition(position);
    _positionButton = position;

    this->setScale(scale);
    _scaleButton = scale;

    this->setHitbox(hitbox);
    this->setDisplay(true);
}

void Button::draw()
{}

void Button::autoManage()
{}

int Button::onClick()
{
    return (0);
}

void Button::onHover(std::string const &path)
{
    sf::Vector2f scale;
    sf::Vector2f position;

    scale = {getScaleButton().x+0.02f, getScaleButton().y+0.02f};
    position = {getPositionButton().x-7.0f, getPositionButton().y-7.0f};
    
    this->setTexture(path);
    this->setScale(scale);
    this->setPosition(position);
}

void Button::basicState()
{
    this->setTexture(getTextureButton());
    this->setScale(getScaleButton());
    this->setPosition(getPositionButton());
}

std::string Button::getTextureButton() const
{
    return _textureButton;
}

sf::Vector2f Button::getScaleButton() const
{
    return _scaleButton;
}

sf::Vector2f Button::getPositionButton() const
{
    return _positionButton;
}