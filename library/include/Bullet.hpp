/*
** Merline, 2019
** Bullet.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class Bullet : public Object 
{
    public:
        Bullet();
        ~Bullet() = default;

        void draw();
        void autoManage();
        void setDirection(sf::Vector2f const &direction);
    private:
        sf::Vector2f _direction;
        float _distance;
        size_t _skin;
        const std::vector<std::string> _skins;
};