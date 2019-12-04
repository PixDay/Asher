/*
** Merline, 2019
** FakeBullet.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class FakeBullet : public Object
{
    public:
        FakeBullet();
        ~FakeBullet() = default;

        void draw();
        void autoManage();
        void setSkin(size_t skin);
    private:
        const std::vector<std::string> _skins;
};