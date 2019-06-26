/*
** EPITECH PROJECT, 2019
** Object.cpp
** File description:
** Adrien Colombier
*/

#include "../include/Object.hpp"

void Object::setTexture(std::string const &string)
{
    this->_texture.loadFromFile(string);
    this->_sprite.setTexture(this->_texture);
}

void Object::setPosition(sf::Vector2f const &position)
{
    this->_position.x = position.x;
    this->_position.y = position.y;
    this->_sprite.setPosition(this->_position);
}

void Object::setPosition(sf::Vector2i const &position)
{
    this->_position.x = static_cast<float>(position.x);
    this->_position.y = static_cast<float>(position.y);
    this->_sprite.setPosition(this->_position);
}

void Object::setScale(sf::Vector2f const &scale)
{
    this->_scale = scale;
    this->_sprite.setScale(this->_scale);
}

void Object::setScale(sf::Vector2i const &scale)
{
    this->_scale.x = static_cast<float>(scale.x);
    this->_scale.y = static_cast<float>(scale.y);
    this->_sprite.setScale(this->_position);
}

void Object::setOrigin(sf::Vector2f const &origin)
{
    this->_origin = origin;
    this->_sprite.setOrigin(this->_origin);
}

void Object::setHitbox(sf::IntRect const &hitbox)
{
    this->_hitbox.left = hitbox.left;
    this->_hitbox.top = hitbox.top;
    this->_hitbox.width = hitbox.width;
    this->_hitbox.height = hitbox.height;
}

void Object::setAngle(float const &angle)
{
    this->_angle = angle;
}

void Object::setSpeed(unsigned int const &speed)
{
    this->_speed = speed;
}

void Object::setLayout(unsigned int const &layout)
{
    this->_layout = layout;
}

sf::Sprite Object::getSprite(void) const
{
    return this->_sprite;
}

sf::Texture Object::getTexture(void) const
{
    return this->_texture;
}

sf::Vector2f Object::getPosition(void) const
{
    return this->_position;
}

sf::Vector2f Object::getScale(void) const
{
    return this->_scale;
}

sf::IntRect Object::getHitbox(void) const
{
    return this->_hitbox;
}

float Object::getAngle() const
{
    return this->_angle;
}

bool Object::hasAnimator(void) const
{
    return this->_animator;
}