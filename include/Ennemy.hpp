/*
** Merline, 2019
** Ennemy.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */
#include <vector>
#include "../library/include/merline.h"

class Ennemy : public Object
{
     public:
        Ennemy();
        ~Ennemy() = default;

        void draw();
        void autoManage();
        size_t getLvl() const;
        bool getFightOn() const;
        void addLvl();
        void setFightOn(bool const &fight);
        void setIa0();
        void setIa1();
        void setIa2();
        void setIa3();
        void Ia0();
        void Ia1();
        void Ia2();
        void Ia3();
        
        sf::Vector2f _target;
        size_t _iaType;
        size_t _lvl;
        size_t _rayon;
        std::vector<sf::Vector2f> _losange;
        size_t _losangePoint;
        bool _fightOn;
};