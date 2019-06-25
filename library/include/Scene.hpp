/*
** Merline, 2019
** Scene.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */
#include "SceneEnum.hpp"

/* CLASS */

class Scene
{
    public:
        virtual SceneEnum playScene() = 0;
};