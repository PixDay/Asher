/*
** EPITECH PROJECT, 2019
** Menu.cpp
** File description:
** Thomas Daullé
*/

#include "Menu.hpp"

Menu::Menu(ObjectManager *manager, Player *player):
    _volume(50)
{
    sf::Vector2f position = {50.0f, 500.0f};
    sf::Vector2f scale = {0.4f, 0.3f};
    sf::IntRect hitbox = {50, 500, 310, 92};

    this->_manager = manager;
    this->_window = manager->getWindow();

    _music.openFromFile("sound/track/WarToWar.ogg");
    _music.play();
    _music.setVolume(_volume);
    _music.setLoop(true);

    this->_background = new Icon("image/Menu/bg_menu.png");
    manager->addObjectMenu(this->_background);

    this->_buttonPlay = new Button("image/Menu/play.jpg", position, scale, hitbox);
    manager->addObjectMenu(this->_buttonPlay);

    position = {50.0f, 600.0f};
    hitbox = {50, 600, 310, 92};
    this->_buttonSkin = new Button("image/Menu/skin.jpg", position, scale, hitbox);
    manager->addObjectMenu(this->_buttonSkin);

    position = {50.0f, 700.0f};
    hitbox = {50, 700, 310, 92};
    this->_buttonOptions = new Button("image/Menu/options.png", position, scale, hitbox);
    manager->addObjectMenu(this->_buttonOptions);

    position = {50.0f, 800.0f};
    hitbox = {50, 800, 310, 92};
    this->_buttonQuit = new Button("image/Menu/quit.jpg", position, scale, hitbox);
    manager->addObjectMenu(this->_buttonQuit);

    position = {550.0f, 450.0f};
    hitbox = {550, 450, 576, 461};
    scale = {0.6, 0.6};
    this->_buttonJoin = new Button("image/Menu/join.jpg", position, scale, hitbox);
    _buttonJoin->setDisplay(false);
    manager->addObjectMenu(this->_buttonJoin);

    position = {1200.0f, 450.0f};
    hitbox = {1200, 450, 576, 461};
    this->_buttonCreate = new Button("image/Menu/create.jpg", position, scale, hitbox);
    _buttonCreate->setDisplay(false);
    manager->addObjectMenu(this->_buttonCreate);

    this->setTexture("image/Menu/cursor_target.png");
    position = {256.0f, 256.0f};
    scale = {0.08f, 0.08f};
    this->setOrigin(position);
    this->setScale(scale);
    this->setDisplay(true);
    this->_player = player;
}

void Menu::draw()
{
}

void Menu::autoManage()
{
    this->updateCursorMenu();
    this->updateButton();
}

void Menu::setMusicVolume(float volume)
{
    _volume = volume;
    _music.setVolume(_volume);
}

void Menu::updateCursorMenu()
{
    this->setPosition(this->_mouse.getPosition(*this->_window));
}

void Menu::updateButton()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonPlay->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
        if (_clock.getElapsedTime().asSeconds() >= 0.4) {
            if (_buttonCreate->getDisplay()) {
                _buttonCreate->setDisplay(false);
                _buttonJoin->setDisplay(false);
            } else {
                _buttonCreate->setDisplay(true);
                _buttonJoin->setDisplay(true);
            }
            _clock.restart();
        }
    }
    if (_buttonPlay->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonPlay->onHover("image/Menu/play_hover.jpg");
    else
        _buttonPlay->basicState();
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonSkin->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _manager->setScene(SceneEnum::MerlineScene::SKIN);
    if (_buttonSkin->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonSkin->onHover("image/Menu/skin_hover.jpg");
    else
        _buttonSkin->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonOptions->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _manager->setScene(SceneEnum::MerlineScene::OPTION);
    if (_buttonOptions->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonOptions->onHover("image/Menu/options_hover.jpg");
    else
        _buttonOptions->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonQuit->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _manager->getWindow()->close();
    if (_buttonQuit->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonQuit->onHover("image/Menu/quit_hover.jpg");
    else
        _buttonQuit->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonJoin->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        if (_buttonJoin->getDisplay())
            _manager->setScene(SceneEnum::MerlineScene::GAME);
    if (_buttonJoin->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonJoin->onHover("image/Menu/join.jpg");
    else
        _buttonJoin->basicState();

    if (_buttonCreate->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonCreate->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
            
            _manager->setScene(SceneEnum::MerlineScene::GAME);
        }
        _buttonCreate->onHover("image/Menu/create.jpg");
    }
    else
        _buttonCreate->basicState();
}