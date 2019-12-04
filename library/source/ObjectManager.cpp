/*
** EPITECH PROJECT, 2019
** ObjectManager.cpp
** File description:
** Adrien Colombier
*/

#include <iostream>
#include "../include/ObjectManager.hpp"

ObjectManager::ObjectManager(std::string &string):
    _scene(SceneEnum::MerlineScene::MENU)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1366, 768), string);
    this->_window->setMouseCursorVisible(false);
    this->_window->setVerticalSyncEnabled(true);
}

ObjectManager::ObjectManager(std::string string):
    _scene(SceneEnum::MerlineScene::MENU)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), string, sf::Style::Fullscreen);
    this->_window->setMouseCursorVisible(false);
    this->_window->setVerticalSyncEnabled(true);
}

ObjectManager::ObjectManager(sf::RenderWindow* window):
    _scene(SceneEnum::MerlineScene::MENU)
{
    this->_window = window;
}

void ObjectManager::draw(void)
{
    sf::Color background(100, 100, 100, 255);
    
    this->_window->clear(background);
    if (this->_scene == SceneEnum::MerlineScene::MENU)
        for (auto object : this->_objectsMenu) {
            if (object->getDisplay())
                this->_window->draw(object->getSprite());
            object->autoManage();
        }
    if (this->_scene == SceneEnum::MerlineScene::GAME)
        for (auto object : this->_objects) {
            if (object->getDisplay())
                this->_window->draw(object->getSprite());
            object->autoManage();
        }
    if (this->_scene == SceneEnum::MerlineScene::OPTION)
        for (auto object : this->_objectsOption) {
            if (object->getDisplay())
                this->_window->draw(object->getSprite());
            object->autoManage();
        }
    if (this->_scene == SceneEnum::MerlineScene::SKIN)
        for (auto object : this->_objectsSkin) {
            if (object->getDisplay())
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

void ObjectManager::setScene(size_t scene)
{
    this->_scene = scene;
}

void ObjectManager::addObject(Object *object)
{
    this->_objects.push_back(object);
}

void ObjectManager::addObjectMenu(Object *object)
{
    this->_objectsMenu.push_back(object);
}

void ObjectManager::addObjectOption(Object *object)
{
    this->_objectsOption.push_back(object);
}

void ObjectManager::addObjectSkin(Object *object)
{
    this->_objectsSkin.push_back(object);
}

sf::RenderWindow *ObjectManager::getWindow() const
{
    return this->_window;
}

std::vector<Object *> ObjectManager::getObject() const
{
    return this->_objectsMenu;
}