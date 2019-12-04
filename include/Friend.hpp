/*
** Merline, 2019
** Friend.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */
#include <vector>
#include <SFML/Audio.hpp>
#include "../library/include/merline.h"

class Friend : public Object
{
     public:
        Friend();
        ~Friend() = default;

        void draw();
        void autoManage();
        std::vector<FakeBullet *> _bullets;
};