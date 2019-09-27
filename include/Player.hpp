/*
** Merline, 2019
** Player.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */
#include <vector>
#include <SFML/Audio.hpp>
#include "../library/include/merline.h"

class Player : public Object
{
    public:
        Player(ObjectManager &manager);
        ~Player() = default;

        void draw();
        void autoManage();
    private:
        void updateCursor();
        void updateMove();
        void updateBullet(sf::Vector2f const &cursor);
        void updateGlow();
        void rollBackSpell();

        size_t _skin;
        const std::vector<std::string> _skins;
        size_t _shoot;
        size_t _currentBullet;
        size_t _glow;
        size_t _currentGlow;
        bool _rollback;
        std::vector<Bullet *> _bullets;
        std::vector<Glow *> _glows;
        sf::RenderWindow *_window;
        Cursor *_cursor;
        sf::Mouse _mouse;
        sf::Clock _moveClock;
        sf::Clock _shootClock;
        sf::Clock _glowClock;
        sf::Music _shotSound;
};