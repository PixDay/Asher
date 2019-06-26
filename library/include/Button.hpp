/*
** Merline, 2019
** Boutton.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include "Ui.hpp"

/* CLASS */

class Button : public Ui
{
    public:
        virtual void onClick();
        virtual void onHover();
    private:
        std::string _name;
};