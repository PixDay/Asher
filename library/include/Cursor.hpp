/*
** Merline, 2019
** Cursor.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class Cursor : public Object 
{
    public:
        Cursor();
        ~Cursor() = default;

        void draw();
        void autoManage();
    private:
        size_t _skin;
        const std::vector<std::string> _skins;
};