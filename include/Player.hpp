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
        Player(ObjectManager &manager);
        ~Player() = default;

        void draw();
        void autoManage();
        void updateCursor();
        void updateMove();
    private:
        size_t _skin;
        const std::vector<std::string> _skins;
        sf::RenderWindow *_window;
        Cursor *_cursor;
        sf::Mouse _mouse;
        sf::Clock _moveClock;
};