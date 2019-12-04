/*
** Merline, 2019
** Button.hpp
** File description:
** Thomas Daullé
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Object.hpp"

class Button : public Object
{
    public:
        Button(std::string const &path, sf::Vector2f position, sf::Vector2f scale, sf::IntRect hitbox);
        ~Button() = default;

        int onClick();
        void onHover(std::string const &path);
        void basicState();

        std::string getTextureButton() const;
        sf::Vector2f getScaleButton() const;
        sf::Vector2f getPositionButton() const;
    
    private:
        /* UTILITIES */
        void draw();
        void autoManage();

        std::string _textureButton;
        sf::Vector2f _scaleButton;
        sf::Vector2f _positionButton;
};

#endif