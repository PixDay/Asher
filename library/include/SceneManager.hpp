/*
** Merline, 2019
** SceneManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include <vector>
#include "Scene.hpp"

/* CLASS */

class SceneManager 
{
    public:
        SceneManager();
        ~SceneManager() = default;

    private:
        std::vector<Scene> _scenes;
        SceneEnum _currentScene;        
};