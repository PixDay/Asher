/*
** Merline, 2019
** ObjectManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

/* INCLUDES */

#include <vector>
#include "Object.hpp"
#include "SceneEnum.hpp"

/* CLASS */

class ObjectManager
{
    public:
        ObjectManager(std::string &string);
        ObjectManager(std::string string);
        ObjectManager(sf::RenderWindow* window);
        ~ObjectManager() = default;

        void draw(void);
        void setSize(unsigned int x, unsigned int y, std::string string);
        void setSize(unsigned int x, unsigned int y, std::string &string);
        void setScene(size_t scene);
        void addObject(Object *object);
        void addObjectMenu(Object *object);
        void addObjectOption(Object *object);
        void addObjectSkin(Object *object);

        /* GETTERS */
        sf::RenderWindow *getWindow() const;
        std::vector<Object *> getObject() const;

    private:
        sf::RenderWindow *_window;
        std::vector<Object *> _objects;
        std::vector<Object *> _objectsMenu;
        std::vector<Object *> _objectsOption;
        std::vector<Object *> _objectsSkin;
        size_t _scene;
};
