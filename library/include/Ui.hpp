/*
** Merline, 2019
** Ui.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Object.hpp"

/* CLASS */

class Ui : public Object
{
    public:
        Ui() = delete;

        /* UTILIIES */
        virtual void autoManage();
};