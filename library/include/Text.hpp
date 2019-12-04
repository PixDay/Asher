/*
** EPITECH PROJECT, 2019
** Text.hpp
** File description:
** Thomas Daullé
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class Text
{
    public:
        Text(const std::string string, sf::Vector2f position, unsigned int size);
        ~Text();

        sf::Text getText() const;
        bool getDrawable() const;
        std::string getString() const;

        void setString(const std::string string);
        void setDrawable(bool display);

    private:
        sf::Text _text;
        sf::Font _font;

        std::string _string;
        sf::Vector2f _position;
        unsigned int _size;
        sf::Color _color;

        bool _isDrawable;
};

#endif