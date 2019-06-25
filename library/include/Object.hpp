/*
** Merline, 2019
** Object.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include <SFML/Graphics.hpp>

/* CLASS */

class Object
{
    public:
    /* SETTERS */
        virtual void setTexture(std::string &string) = 0;
        virtual void setTexture(std::string string) = 0;
        virtual void setPosition(sf::Vector2f &position) = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual void setPosition(sf::Vector2i &position) = 0;
        virtual void setPosition(sf::Vector2i position) = 0;
        virtual void setScale(sf::Vector2f &scale) = 0;
        virtual void setScale(sf::Vector2f scale) = 0;
        virtual void setScale(sf::Vector2i &scale) = 0;
        virtual void setScale(sf::Vector2i scale) = 0;
        virtual void setHitbox(sf::IntRect &hitbox) = 0;
        virtual void setHitbox(sf::IntRect hitbox) = 0;

    /* GETTERS */
        virtual sf::Sprite getSprite(void) const = 0;
        virtual sf::Vector2f getPosition(void) const = 0;
        virtual sf::Vector2f getScale(void) const = 0;
        virtual sf::IntRect getHitbox(void) const = 0;
        virtual bool hasAnimator(void) const = 0;

    /* UTILIIES */
        virtual void draw(void) = 0;

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::IntRect _hitbox;
        bool _animator;
};
