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
    this->_window->clear(sf::Color::Black);
    for (size_t i = 0; i < this->_objects.size(); i++) {
        this->_window->draw(this->_objects[i]->getSprite());
    }
    this->_window->display();
}

void ObjectManager::setSize(unsigned int x, unsigned int y, std::string string)
{
    delete this->_window;
    this->_window = new sf::RenderWindow(sf::VideoMode(x, y), string);
}

void ObjectManager::addObject(Object *object)
{
    this->_objects.push_back(object);
}

sf::RenderWindow *ObjectManager::getWindow() const
{
    return this->_window;
}