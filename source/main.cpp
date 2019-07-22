/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Adrien Colombier
*/

#include "main.h"

int main(int argc, char **argv, char **env)
{
    (void)argc, (void)argv, (void)env;
    ObjectManager manager("Asher");
    sf::Event event;

    manager.addObject(new Player(manager));
    while (manager.getWindow()->isOpen()) {
        while (manager.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                manager.getWindow()->close();
            manager.draw();
        }
    }
    return EXIT_SUCCESS;
}
