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
#include <iostream>
#include <fstream>
#include <string>
#include "../library/include/merline.h"

class Player : public Object
{
    public:
        Player(ObjectManager &manager);
        ~Player() = default;

        void draw();
        void autoManage();

        void setForward(size_t forward);
        void setBackward(size_t backward);
        void setRight(size_t right);
        void setLeft(size_t left);
        void setDash(size_t dash);
        void setRollBack(size_t rollBack);
        void readSave();
        void writeSave();

    private:
        void updateCursor();
        void updateTp();
        void updateMove();
        void updateBullet(sf::Vector2f const &cursor);
        void updateGlow();
        void rollBackSpell();
        void changeWeapon();
        void updateQuote();
        void updateSpeed();
        void updateEnnemy();
        bool isFightOn();
        bool ennemyKilled(sf::Vector2f const &position, sf::IntRect const &hitbox) const;
        void checkAlive();

        size_t getForward() const;
        size_t getBackward() const ;
        size_t getRight() const;
        size_t getLeft() const;
        size_t getDash() const;
        size_t getRollBack() const;
        

        bool _soundSpeed;
        size_t _skin;
        size_t _weapon;
        const std::vector<std::string> _skins;
        const std::vector<std::string> _quotes;
        size_t _shoot;
        size_t _currentBullet;
        size_t _glow;
        size_t _currentGlow;
        bool _rollback;
        size_t _keyForward;
        size_t _keyBackward;
        size_t _keyRight;
        size_t _keyLeft;
        size_t _keyDash;
        size_t _keyRollBack;
        std::vector<Bullet *> _bullets;
        std::vector<Glow *> _glows;
        sf::RenderWindow *_window;
        Cursor *_cursor;
        BlackHole *_tp;
        sf::Mouse _mouse;
        sf::Clock _moveClock;
        sf::Clock _shootClock;
        sf::Clock _glowClock;
        sf::Clock _tpClock;
        sf::Clock _weaponClock;
        sf::Clock _rollClock;
        sf::Clock _speedClock;
        sf::Music _shotSound;
        sf::Music _rollSound;
        sf::Music _dashSound;
        sf::Music _speedSound;
        sf::Music _switchSound;
        std::vector<sf::Music *> _quoteSound;
        ObjectManager *_manager;
        std::vector<Ennemy *> _ennemies;
        bool _stageOn;
        bool _alive;
};