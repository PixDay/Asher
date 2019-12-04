/*
** EPITECH PROJECT, 2019
** Option.hpp
** File description:
** Thomas Daullé
*/

#ifndef OPTION_HPP_
#define OPTION_HPP_

#include <iostream>
#include "../library/include/merline.h"
#include "Menu.hpp"
#include "Player.hpp"

class Option : public Object
{
    public:

        Option(ObjectManager *manager, Menu *menu, Player *player);
        ~Option() = default;

        /* UTILITIES */
        void draw(void);
        void autoManage(void);

        void initText();
        void initButton();

        const std::string findKeyString(sf::Keyboard::Key key);
        void changeKey(int toChange);
        int getIndexKeyToChange();
        void keyWaitingToChange(Text *textToChange);

    private:
        void updateCursorOption();
        void updateButton();

        ObjectManager *_manager;
        Menu *_menu;
        Player *_player;
        sf::RenderWindow *_window;
        sf::Mouse _mouse;

        Icon *_background;
        Button *_buttonBack;
        Icon *_cursorVolume;
        sf::IntRect _hitboxLine;

        /* KEYS */
        std::vector<std::string> _keyString;
        std::vector<Text *> _tabKeyText;
        std::vector<sf::Keyboard::Key *> _tabKeyBind;
        std::vector<void (Player::*)(size_t)> _setterKey;


        sf::Keyboard::Key _keyForward;
        Text *_textForward;
        Button *_buttonKeyForward;

        sf::Keyboard::Key _keyBackward;
        Text *_textBackward;
        Button *_buttonKeyBackward;

        sf::Keyboard::Key _keyRight;
        Text *_textRight;
        Button *_buttonKeyRight;

        sf::Keyboard::Key _keyLeft;
        Text *_textLeft;
        Button *_buttonKeyLeft;

        sf::Keyboard::Key _keyDash;
        Text *_textDash;
        Button *_buttonKeyDash;

        sf::Keyboard::Key _keyRollback;
        Text *_textRollback;
        Button *_buttonKeyRollback;

        sf::Keyboard::Key _keySpeedup;
        Text *_textSpeedup;
        Button *_buttonKeySpeedup;

        sf::Keyboard::Key _keyWeapon;
        Text *_textWeapon;
        Button *_buttonKeyWeapon;
};

#endif