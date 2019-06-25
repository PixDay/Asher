/*
** EPITECH PROJECT, 2019
** ObjectManager.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/ObjectManager.hpp"

ObjectManager::ObjectManager(std::string &string)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1366, 768), string);
    std::cout << "create window with " << string << " as name !" << std::endl;
}

ObjectManager::ObjectManager(std::string string)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1366, 768), string);
    std::cout << "create window with " << string << " as name !" << std::endl;
}

void ObjectManager::draw(void)
{
    std::cout << "this magic shit should draw everything ! " << std::endl;
}
