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
    this->_window->setMouseCursorVisible(false);
}

ObjectManager::ObjectManager(std::string string)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1366, 768), string);
    std::cout << "create window with " << string << " as name !" << std::endl;
    this->_window->setMouseCursorVisible(false);
}

void ObjectManager::draw(void)
{
    this->_window->clear(sf::Color::White);
    for (auto object : this->_objects) {
        this->_window->draw(object->getSprite());
        object->autoManage();
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