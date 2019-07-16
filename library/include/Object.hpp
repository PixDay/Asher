/*
** Merline, 2019
** Object.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include <SFML/Graphics.hpp>
#include <cmath>

/* CLASS */

class Object
{
    public:
    /* SETTERS */
        void setTexture(std::string const &string);
        void setPosition(sf::Vector2f const &position);
        void setPosition(sf::Vector2i const &position);
        void setScale(sf::Vector2f const &scale);
        void setScale(sf::Vector2i const &scale);
        void setOrigin(sf::Vector2f const &origin);
        void setHitbox(sf::IntRect const &hitbox);
        void setAngle(float const angle);
        void setAngle(sf::Vector2f const &target);
        void setSpeed(unsigned int const &speed);
        void setLayout(unsigned int const &layout);

    /* GETTERS */
        sf::Sprite getSprite(void) const;
        sf::Texture getTexture(void) const;
        sf::Vector2f getPosition(void) const;
        sf::Vector2f getScale(void) const;
        sf::IntRect getHitbox(void) const;
        float getAngle() const;
        bool hasAnimator(void) const;

    /* UTILIIES */
        virtual void draw(void) = 0;
        virtual void autoManage() = 0;
        
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::Vector2f _origin;
        sf::IntRect _hitbox;
        float _angle;
        unsigned int _speed;
        unsigned int _layout;
        bool _hover;
        bool _animator;
};
