/*
** Merline, 2019
** Player.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */
#include <vector>
#include "../library/include/merline.h"

class Player : public Object
{
    public:
        Player();
        ~Player() = default;

        void draw();
        void autoManage();
    private:
        const std::vector<std::string> _skins;
};