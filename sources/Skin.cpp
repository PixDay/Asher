/*
** EPITECH PROJECT, 2019
** Skin.cpp
** File description:
** Thomas Daullé
*/

#include "Skin.hpp"

Skin::Skin(ObjectManager *manager, Player *player):
    _skinsPath({"image/skin/defaultSkin.png", 
    "image/skin/negatifSkin.png", "image/skin/blueSkin.png",
    "image/skin/cyanSkin.png", "image/skin/greenSkin.png",
    "image/skin/jauneSkin.png", "image/skin/magentaSkin.png",
    "image/skin/redSkin.png", "image/skin/negatifBlueSkin.png",
    "image/skin/negatifCyanSkin.png", "image/skin/negatifGreenSkin.png",
    "image/skin/negatifJauneSkin.png", "image/skin/negatifMagentaSkin.png",
    "image/skin/negatifRedSkin.png"})
{
    sf::Vector2f position = {850, 550};
    sf::Vector2f scale = {0.5, 0.5};
    sf::IntRect hitbox = {25, 45, 130, 130};

    _manager = manager;
    _window = manager->getWindow();
    _player = player;

    _background = new Icon("image/Menu/skin_menu.jpg");
    manager->addObjectSkin(_background);

    for (size_t i = 0; i < _skinsPath.size(); i++) {
        _skinsTab.push_back(new Icon(_skinsPath[i]));
        _skinsTab[i]->setPosition(position);
        _skinsTab[i]->setDisplay(false);
    }
    _skinsTab[0]->setDisplay(true);
    _currentSkin = 0;

    for (auto skin : _skinsTab)
        manager->addObjectSkin(skin);

    position = {1400, 40};
    _selectedSkin = new Icon("image/skin/defaultSkin.png");
    manager->addObjectSkin(_selectedSkin);
    _selectedSkin->setScale(scale);
    _selectedSkin->setPosition(position);

    scale = {1, 1};
    position = {25, 45};
    _buttonBack = new Button("image/Menu/back.png", position, scale, hitbox);
    _manager->addObjectSkin(_buttonBack);

    position = {500, 680};
    hitbox = {500, 680, 125, 125};
    _buttonPrev = new Button("image/Menu/left_arrow.png", position, scale, hitbox);
    _manager->addObjectSkin(_buttonPrev);

    position = {1350, 680};
    hitbox = {1350, 680, 125, 125};
    _buttonNext = new Button("image/Menu/right_arrow.png", position, scale, hitbox);
    _manager->addObjectSkin(_buttonNext);

    position = {840, 945};
    hitbox = {840, 945, 307, 86};
    scale = {0.4f, 0.3f};
    _buttonSelect = new Button("image/Menu/select.jpg", position, scale, hitbox);
    _manager->addObjectSkin(_buttonSelect);

    this->setTexture("image/Menu/cursor_target.png");
    position = {256.0f, 256.0f};
    scale = {0.08f, 0.08f};
    this->setOrigin(position);
    this->setScale(scale);
    this->setDisplay(true);
}

void Skin::autoManage()
{
    updateCursorSkin();
    updateButton();
}

void Skin::draw()
{}

void Skin::updateCursorSkin()
{
    this->setPosition(this->_mouse.getPosition(*this->_window));
}

void Skin::updateButton()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonBack->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _manager->setScene(SceneEnum::MerlineScene::MENU);
    if (_buttonBack->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonBack->onHover("image/Menu/back.png");
    else
        _buttonBack->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonPrev->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
        if (_clock.getElapsedTime().asSeconds() >= 0.2) {
            _skinsTab[_currentSkin]->setDisplay(false);
            if (_currentSkin == 0)
                _currentSkin = _skinsTab.size()-1;
            else
                _currentSkin--;
            _skinsTab[_currentSkin]->setDisplay(true);
            _clock.restart();
        }
    }
    if (_buttonPrev->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonPrev->onHover("image/Menu/left_arrow.png");
    else
        _buttonPrev->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonNext->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
        if (_clock.getElapsedTime().asSeconds() >= 0.2) {
            _skinsTab[_currentSkin]->setDisplay(false);
            if (_currentSkin == _skinsTab.size()-1)
                _currentSkin = 0;
            else
                _currentSkin++;
            _skinsTab[_currentSkin]->setDisplay(true);
            _clock.restart();
        }
    }
    if (_buttonNext->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonNext->onHover("image/Menu/right_arrow.png");
    else
        _buttonNext->basicState();
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonSelect->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
        _player->setTexture(_skinsPath[_currentSkin]);
        _selectedSkin->setTexture(_skinsPath[_currentSkin]);
    }
    if (_buttonSelect->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonSelect->onHover("image/Menu/select_hover.png");
    else
        _buttonSelect->basicState();
}