/*
** EPITECH PROJECT, 2019
** Skin.hpp
** File description:
** Thomas Daullé
*/

#ifndef SKIN_HPP_
#define SKIN_HPP_

#include <iostream>
#include "../library/include/merline.h"
#include "Player.hpp"

class Skin : public Object
{
    public:

        Skin(ObjectManager *manager, Player *player);
        ~Skin() = default;

        /* UTILITIES */
        void draw(void);
        void autoManage(void);

    private:
        void updateCursorSkin();
        void updateButton();

        ObjectManager *_manager;
        sf::RenderWindow *_window;
        Player *_player;
        sf::Mouse _mouse;

        Icon *_background;

        sf::Clock _clock;

        /* BUTTONS */
        Button *_buttonBack;
        Button *_buttonPrev;
        Button *_buttonNext;
        Button *_buttonSelect;

        /* SKINS */
        Icon *_selectedSkin;
        std::vector<Icon *> _skinsTab;
        const std::vector<std::string> _skinsPath;
        size_t _currentSkin;
};

#endif