/*
** Merline, 2019
** Menu.hpp
** File description:
** Thomas Daullé
*/

#pragma once

#include <iostream>
#include "../library/include/merline.h"
#include "Player.hpp"

class Menu : public Object
{
    public:

        Menu(ObjectManager *manager, Player *player);
        ~Menu() = default;

        /* UTILITIES */
        void draw(void);
        void autoManage(void);

        void setMusicVolume(float volume);

    private:
        void updateCursorMenu();
        void updateButton();

        ObjectManager *_manager;
        Player *_player;
        sf::RenderWindow *_window;
        sf::Mouse _mouse;

        sf::Music _music;
        float _volume;

        sf::Clock _clock;

        Icon *_background;
        Icon *_gameIcon;
        std::vector<Button *> _buttons;
        Button *_buttonPlay;
        Button *_buttonSkin;
        Button *_buttonOptions;
        Button *_buttonQuit;
        Button *_buttonJoin;
        Button *_buttonCreate;
};