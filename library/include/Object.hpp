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
        Object() = delete;

    /* SETTERS */
        void setTexture(std::string &string);
        void setTexture(std::string string);
        void setPosition(sf::Vector2f &position);
        void setPosition(sf::Vector2f position);
        void setPosition(sf::Vector2i &position);
        void setPosition(sf::Vector2i position);
        void setScale(sf::Vector2f &scale);
        void setScale(sf::Vector2f scale);
        void setScale(sf::Vector2i &scale);
        void setScale(sf::Vector2i scale);
        void setHitbox(sf::IntRect &hitbox);
        void setHitbox(sf::IntRect hitbox);
        void setAngle(float angle);
        void setSpeed(unsigned int speed);

    /* GETTERS */
        sf::Sprite getSprite(void) const;
        sf::Vector2f getPosition(void) const;
        sf::Vector2f getScale(void) const;
        sf::IntRect getHitbox(void) const;
        float getAngle() const;
        bool hasAnimator(void) const;

    /* UTILIIES */
        virtual void draw(void) = 0;

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::IntRect _hitbox;
        float _angle;
        unsigned int _speed;
        bool _hover;
        bool _animator;
};
