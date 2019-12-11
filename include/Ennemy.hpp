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
        

        sf::Vector2f _target;
};