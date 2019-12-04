/*
** EPITECH PROJECT, 2019
** Option.cpp
** File description:
** Thomas Daullé
*/

#include "Option.hpp"

Option::Option(ObjectManager *manager, Menu *menu, Player *player):
    _keyString({"A", "B", "C", "D", "E", "F", "G", "H",
    "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2",
    "3", "4", "5", "6", "7", "8", "9", "Esc", "LCtrl", "LShift",
    "LAlt", "Systm", "RCtrl", "RShift", "RAlt", "RSystem", "Menu",
    "[", "]", ";", ",", ".", "\"", "/", "\\", "~", "=", "-", "Spac",
    "Entr", "Back", "Tab", "PgUp", "PgDown", "End", "Home", "Insr", "Del",
    "+", "-", "*", "/", "Left", "Right", "Up", "Down", "p0", "p1",
    "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "F1", "F2", "F3",
    "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13",
    "F14", "F15", "Paus", "KeyC", "-", "Back", "\\", ";", "Entr", "??"}),
    _keyForward(sf::Keyboard::Key::Z),
    _keyBackward(sf::Keyboard::Key::S),
    _keyRight(sf::Keyboard::Key::D),
    _keyLeft(sf::Keyboard::Key::Q),
    _keyDash(sf::Keyboard::Key::E),
    _keyRollback(sf::Keyboard::Key::R),
    _keySpeedup(sf::Keyboard::Key::A),
    _keyWeapon(sf::Keyboard::Key::LShift)
{
    sf::Vector2f position = {25, 45};
    sf::Vector2f scale = {1, 1};
    sf::IntRect hitbox = {25, 45, 130, 130};
    sf::Vector2f origin = {17, 35};
    _hitboxLine = {575, 320, 785, 55};
    
    _manager = manager;
    _menu = menu;
    _player = player;
    _window = manager->getWindow();
    
    _tabKeyBind.push_back(&_keyForward);
    _tabKeyBind.push_back(&_keyBackward);
    _tabKeyBind.push_back(&_keyRight);
    _tabKeyBind.push_back(&_keyLeft);
    _tabKeyBind.push_back(&_keyDash);
    _tabKeyBind.push_back(&_keyRollback);

    _setterKey.push_back(&Player::setForward);
    _setterKey.push_back(&Player::setBackward);
    _setterKey.push_back(&Player::setRight);
    _setterKey.push_back(&Player::setLeft);
    _setterKey.push_back(&Player::setDash);
    _setterKey.push_back(&Player::setRollBack);

    _background = new Icon("image/Menu/option_menu.jpg");
    manager->addObjectOption(_background);

    _buttonBack = new Button("image/Menu/back.png", position, scale, hitbox);
    _manager->addObjectOption(_buttonBack);

    origin = {17, 35};
    position = {967, 345};
    _cursorVolume = new Icon("image/Menu/cursor_volume.jpg");
    _cursorVolume->setOrigin(origin);
    _cursorVolume->setPosition(position);
    _manager->addObjectOption(_cursorVolume);
    
    initText();
    initButton();

    this->setTexture("image/Menu/cursor_target.png");
    position = {256.0f, 256.0f};
    scale = {0.08f, 0.08f};
    this->setOrigin(position);
    this->setScale(scale);
    this->setDisplay(true);
}

void Option::autoManage()
{
    int toChange = getIndexKeyToChange();

    if (toChange != -1)
        changeKey(toChange);
    updateCursorOption();
    updateButton();
    draw();
}

void Option::draw()
{
    if (_textForward->getDrawable())
        _window->draw(_textForward->getText());

    if (_textBackward->getDrawable())
        _window->draw(_textBackward->getText());

    if (_textRight->getDrawable())
        _window->draw(_textRight->getText());

    if (_textLeft->getDrawable())
        _window->draw(_textLeft->getText());

    if (_textDash->getDrawable())
        _window->draw(_textDash->getText());

    if (_textRollback->getDrawable())
        _window->draw(_textRollback->getText());
}

const std::string Option::findKeyString(sf::Keyboard::Key key)
{
    size_t index = (size_t)key;

    return(_keyString[index]);
}

void Option::changeKey(int toChange)
{
    size_t newKey = 0;

    while (newKey < 107 && !sf::Keyboard::isKeyPressed((sf::Keyboard::Key)newKey))
            newKey++;
    if (newKey < 107) {
        _tabKeyText[toChange]->setString(findKeyString((sf::Keyboard::Key)newKey));
        _tabKeyText[toChange]->setDrawable(true);
        *_tabKeyBind[toChange] = (sf::Keyboard::Key)newKey;
        (_player->*_setterKey[toChange])(newKey);
    }
}

int Option::getIndexKeyToChange()
{
    for (size_t i = 0; i < _tabKeyText.size(); i++) {
        if (_tabKeyText[i]->getDrawable() == false)
            return (i);
    }
    return (-1);
}

void Option::keyWaitingToChange(Text *textToChange)
{
    for (auto key : _tabKeyText)
        key->setDrawable(true);
    if (textToChange !=  nullptr)
        textToChange->setDrawable(false);
}

void Option::updateCursorOption()
{
    this->setPosition(this->_mouse.getPosition(*this->_window));
}

void Option::updateButton()
{
    sf::Vector2f newPosCursorVolume;
    float volume;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _hitboxLine.contains(this->_mouse.getPosition(*this->_window))) {
        newPosCursorVolume.x = _mouse.getPosition(*this->_window).x;
        newPosCursorVolume.y = _cursorVolume->getPosition().y;
        _cursorVolume->setPosition(newPosCursorVolume);
        volume = _cursorVolume->getPosition().x - 575.0f;
        _menu->setMusicVolume((volume*100)/785);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonBack->getHitbox().contains(this->_mouse.getPosition(*this->_window))) {
        keyWaitingToChange(nullptr);
        _manager->setScene(SceneEnum::MerlineScene::MENU);
    }
    if (_buttonBack->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonBack->onHover("image/Menu/back.png");
    else
        _buttonBack->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonKeyForward->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        keyWaitingToChange(_textForward);
    if (_buttonKeyForward->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonKeyForward->onHover("image/Menu/button.jpg");
    else
        _buttonKeyForward->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonKeyBackward->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        keyWaitingToChange(_textBackward);
    if (_buttonKeyBackward->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonKeyBackward->onHover("image/Menu/button.jpg");
    else
        _buttonKeyBackward->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonKeyRight->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        keyWaitingToChange(_textRight);
    if (_buttonKeyRight->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonKeyRight->onHover("image/Menu/button.jpg");
    else
        _buttonKeyRight->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonKeyLeft->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        keyWaitingToChange(_textLeft);
    if (_buttonKeyLeft->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonKeyLeft->onHover("image/Menu/button.jpg");
    else
        _buttonKeyLeft->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonKeyDash->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        keyWaitingToChange(_textDash);
    if (_buttonKeyDash->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonKeyDash->onHover("image/Menu/button.jpg");
    else
        _buttonKeyDash->basicState();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _buttonKeyRollback->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        keyWaitingToChange(_textRollback);
    if (_buttonKeyRollback->getHitbox().contains(this->_mouse.getPosition(*this->_window)))
        _buttonKeyRollback->onHover("image/Menu/button.jpg");
    else
        _buttonKeyRollback->basicState();
}

void Option::initText()
{
    sf::Vector2f position = {0, 0};
    unsigned int size = 120;

    position = {925, 475};
    _textForward = new Text(findKeyString(_keyForward), position, size);
    _tabKeyText.push_back(_textForward);
    position = {925, 615};
    _textBackward = new Text(findKeyString(_keyBackward), position, size);
    _tabKeyText.push_back(_textBackward);
    position = {925, 765};
    _textRight = new Text(findKeyString(_keyRight), position, size);
    _tabKeyText.push_back(_textRight);
    position = {925, 910};
    _textLeft = new Text(findKeyString(_keyLeft), position, size);
    _tabKeyText.push_back(_textLeft);
    position = {1555, 475};
    _textDash = new Text(findKeyString(_keyDash), position, size);
    _tabKeyText.push_back(_textDash);
    position = {1555, 625};
    _textRollback = new Text(findKeyString(_keyRollback), position, size);
    _tabKeyText.push_back(_textRollback);
}

void Option::initButton()
{
    sf::Vector2f position;
    sf::IntRect hitbox;
    sf::Vector2f scale = {1, 1};

    position = {900, 520};
    hitbox = {900, 520, 100, 100};
    _buttonKeyForward = new Button("image/Menu/button.jpg", position, scale, hitbox);
    _manager->addObjectOption(_buttonKeyForward);

    position = {900, 670};
    hitbox = {900, 670, 100, 100};
    _buttonKeyBackward = new Button("image/Menu/button.jpg", position, scale, hitbox);
    _manager->addObjectOption(_buttonKeyBackward);

    position = {900, 820};
    hitbox = {900, 820, 100, 100};
    _buttonKeyRight = new Button("image/Menu/button.jpg", position, scale, hitbox);
    _manager->addObjectOption(_buttonKeyRight);

    position = {900, 965};
    hitbox = {900, 965, 100, 100};
    _buttonKeyLeft = new Button("image/Menu/button.jpg", position, scale, hitbox);
    _manager->addObjectOption(_buttonKeyLeft);

    position = {1530, 520};
    hitbox = {1530, 520, 100, 100};
    _buttonKeyDash = new Button("image/Menu/button.jpg", position, scale, hitbox);
    _manager->addObjectOption(_buttonKeyDash);

    position = {1530, 680};
    hitbox = {1530, 680, 100, 100};
    _buttonKeyRollback = new Button("image/Menu/button.jpg", position, scale, hitbox);
    _manager->addObjectOption(_buttonKeyRollback);
}