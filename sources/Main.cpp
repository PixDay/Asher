/*
** EPITECH PROJECT, 2019
** Main.cpp
** File description:
** Adrien Colombier
*/

#include "Main.hpp"

int main(int argc, char **argv, char **env)
{
    (void)argc, (void)argv, (void)env;
    std::srand(std::time(nullptr));
    ObjectManager manager("Asher");
    MapManager map(manager);
    sf::Event event;
    
    Player *player = new Player(manager);
    Menu *menu = new Menu(&manager, player);
    manager.addObject(player);
    manager.addObjectMenu(menu);
    manager.addObjectOption(new Option(&manager, menu, player));
    manager.addObjectSkin(new Skin(&manager, player));
    while (manager.getWindow()->isOpen()) {
        while (manager.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                manager.getWindow()->close();
        }
        manager.draw();
    }
    return EXIT_SUCCESS;
}
