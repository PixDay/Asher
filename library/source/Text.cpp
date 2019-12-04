/*
** EPITECH PROJECT, 2019
** Text.cpp
** File description:
** Thomas Daullé
*/

#include "../include/Text.hpp"

Text::Text(const std::string string, sf::Vector2f position, unsigned int size)
{
    _font.loadFromFile("image/Font/game_over.ttf");
    _string.assign(string);
    _position = position;
    _size = size;
    _color = sf::Color::Black;

    _text.setFont(_font);
    _text.setString(string);
    _text.setPosition(position);
    _text.setCharacterSize(size);
    _text.setFillColor(_color);

    _isDrawable = true;
}

Text::~Text()
{}

sf::Text Text::getText() const
{
    return (_text);
}

bool Text::getDrawable() const
{
    return (_isDrawable);
}

std::string Text::getString() const
{
    return (_string);
}

void Text::setString(const std::string string)
{
    _string.assign(string);
    _text.setString(string);
}

void Text::setDrawable(bool display)
{
    _isDrawable = display;
}