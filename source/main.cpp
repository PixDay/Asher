/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Adrien Colombier
*/

#include "main.h"
#include "../library/include/merline.h"

int main(int argc, char **argv, char **env)
{
    (void)argc, (void)argv, (void)env;
    ObjectManager manager("Asher");
 
    while (manager.getWindow()->isOpen()) {
        sf::Event event;
        while (manager.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                manager.getWindow()->close();
        }
    }
    manager.draw();
    return EXIT_SUCCESS;
}
