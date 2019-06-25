/*
** Merline, 2019
** ObjectManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include <vector>
#include "Object.hpp"

/* CLASS */

class ObjectManager
{
    public:
        ObjectManager(std::string &string);
        ObjectManager(std::string string);
        ~ObjectManager() = default;

        void draw(void);
        void setSize(unsigned int x, unsigned int y, std::string string);
        void setSize(unsigned int x, unsigned int y, std::string &string);
        sf::RenderWindow *getWindow() const;

    private:
        sf::RenderWindow *_window;
        std::vector<Object *> _objects;
};
