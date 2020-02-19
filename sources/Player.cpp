/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** Adrien Colombier
*/

#include "Player.hpp"

Player::Player(ObjectManager &manager) :
    _soundSpeed(false),
    _skin(0),
    _weapon(3),
    _skins({"image/skin/defaultSkin.png", 
    "image/skin/negatifSkin.png", "image/skin/blueSkin.png",
    "image/skin/cyanSkin.png", "image/skin/greenSkin.png",
    "image/skin/jauneSkin.png", "image/skin/magentaSkin.png",
    "image/skin/redSkin.png", "image/skin/negatifBlueSkin.png",
    "image/skin/negatifCyanSkin.png", "image/skin/negatifGreenSkin.png",
    "image/skin/negatifJauneSkin.png", "image/skin/negatifMagentaSkin.png",
    "image/skin/negatifRedSkin.png"}),
    _quotes({"sound/quote/advice_quit.ogg", "sound/quote/amuse_me.ogg", "sound/quote/ennemy_best.ogg", 
    "sound/quote/perfect_place.ogg", "sound/quote/proud_ability.ogg"}),
    _shoot(20),
    _currentBullet(0),
    _glow(30),
    _currentGlow(0),
    _rollback(false),
    _keyForward(sf::Keyboard::Z),
    _keyBackward(sf::Keyboard::S),
    _keyRight(sf::Keyboard::D),
    _keyLeft(sf::Keyboard::Q),
    _keyDash(sf::Keyboard::E),
    _keyRollBack(sf::Keyboard::R),
    _stageOn(false),
    _alive(true)
{
    sf::Vector2f origin = {150.0f, 150.0f};
    sf::Vector2f position = {200.0f, 200.0f};
    sf::Vector2f scale = {0.25f, 0.25f};

    this->_manager = &manager;
    this->setPosition(position);
    this->setTexture(this->_skins[this->_skin]);
    this->setOrigin(origin);
    this->setScale(scale);
    this->setSpeed(12.5f);
    this->setDisplay(true);
    this->_shotSound.openFromFile("sound/spell/shot.wav");
    this->_rollSound.openFromFile("sound/spell/rollBack.ogg");
    this->_dashSound.openFromFile("sound/spell/dash.ogg");
    this->_speedSound.openFromFile("sound/spell/speed.ogg");
    this->_switchSound.openFromFile("sound/spell/switch.ogg");
    this->_cursor = new Cursor();
    this->_tp = new BlackHole();
    this->_window = manager.getWindow();
    manager.addObject(this->_tp);
    for (auto quote : this->_quotes) {
        sf::Music *tmp = new sf::Music();
        tmp->openFromFile(quote);
        this->_quoteSound.push_back(tmp);
    }
    for (size_t bullet_number = 0; bullet_number < this->_shoot; bullet_number++)
        this->_bullets.push_back(new Bullet());
    for (size_t glow_number = 0; glow_number < this->_glow; glow_number++)
        this->_glows.push_back(new Glow());
    for (size_t ennemies_number = 0; ennemies_number < 70; ennemies_number++)
        this->_ennemies.push_back(new Ennemy());
    for (auto glow : this->_glows)
        manager.addObject(glow);
    for (auto ennemy : this->_ennemies)
        manager.addObject(ennemy);
    for (auto bullet : this->_bullets)
        manager.addObject(bullet);
    manager.addObject(this->_cursor);
}

void Player::draw()
{
}

void Player::autoManage()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this->writeSave();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || this->_alive == false) {
        this->_manager->setScene(SceneEnum::MerlineScene::MENU);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        this->_stageOn = true;
    }
    if (!this->_rollback) {
        this->updateMove();
        this->updateCursor();
        this->setAngle(this->_cursor->getPosition());
        this->updateBullet(this->_cursor->getPosition());
        this->updateGlow();
        this->updateSpeed();
        this->checkAlive();
    }
    this->updateTp();
    this->changeWeapon();
    this->updateQuote();
    this->rollBackSpell();
    this->updateEnnemy();
}

void Player::updateCursor()
{
    sf::Vector2f controller;

    controller = (sf::Vector2f)this->_mouse.getPosition(*this->_window);

    controller.x += (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::U)) >= 40 ? sf::Joystick::getAxisPosition(0, sf::Joystick::U) / 5.0f : 0);
    controller.y += (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::V)) >= 40 ? sf::Joystick::getAxisPosition(0, sf::Joystick::V) / 5.0f : 0);
    this->_mouse.setPosition((sf::Vector2i)controller);
    this->_cursor->setPosition(controller);
}

void Player::updateTp()
{
    sf::Vector2f tmp = this->getPosition();

    tmp.x = (tmp.x + this->_cursor->getPosition().x) / 2;
    tmp.y = (tmp.y + this->_cursor->getPosition().y) / 2;
    tmp.x = (tmp.x + this->getPosition().x) / 2;
    tmp.y = (tmp.y + this->getPosition().y) / 2;
    tmp.x = (tmp.x + this->getPosition().x) / 2;
    tmp.y = (tmp.y + this->getPosition().y) / 2;
    this->_tp->setPosition(tmp);
    if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->_keyDash) || sf::Joystick::getAxisPosition(0, sf::Joystick::Z) >= 30) && this->_tpClock.getElapsedTime().asSeconds() >= 2.0f) {
        this->setPosition(tmp);
        this->_dashSound.play();
        this->_tpClock.restart();
    }
    if (this->_tpClock.getElapsedTime().asSeconds() <= 0.35f)
        this->setPosition(tmp);
}

void Player::updateMove()
{
    sf::Vector2f position = this->getPosition();

    if (this->_moveClock.getElapsedTime().asSeconds() >= 0.008f) {
        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->_keyLeft) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) <= -50) && this->getPosition().x >= 50.0f) {
            position.x = position.x - (this->getSpeed() * ((this->_soundSpeed) ? 2.0f : 1.0f));
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->_keyRight) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) >= 50) && this->getPosition().x <= 1870.0f) {
            position.x = position.x + (this->getSpeed() * ((this->_soundSpeed) ? 2.0f : 1.0f));
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->_keyBackward) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) >= 50) && this->getPosition().y <= 1030) {
            position.y += (this->getSpeed() * ((this->_soundSpeed) ? 2.0f : 1.0f));
            this->setPosition(position);
            this->_moveClock.restart();
        }
        if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->_keyForward) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) <= -50) && this->getPosition().y >= 50.0f) {
            position.y -= (this->getSpeed() * ((this->_soundSpeed) ? 2.0f : 1.0f));
            this->setPosition(position);
            this->_moveClock.restart();
        }
    }
}

void Player::updateBullet(sf::Vector2f const &cursor)
{
    sf::Vector2f tmpC = cursor;
    sf::Vector2f tmpV = this->getPosition();
    sf::Vector2f res;

    for (size_t bullet_number = 0; bullet_number < this->_shoot; bullet_number++)
        if (this->_bullets[bullet_number]->getDisplay() == false)
            this->_bullets[this->_currentBullet]->setPosition(this->getPosition());
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::R) >= 30) && 
    this->_shootClock.getElapsedTime().asSeconds() >= this->_bullets[(this->_currentBullet != 0) ? this->_currentBullet - 1 : this->_shoot - 1]->_timeReload) {
        this->_shotSound.play();
        this->_bullets[this->_currentBullet]->setAngle(this->getAngle());
        this->_bullets[this->_currentBullet]->setDisplay(true);
        if (this->_weapon == 0) {
            this->_bullets[this->_currentBullet]->setRange(500.0f);
            this->_bullets[this->_currentBullet]->setDistance(500.0f);
            this->_bullets[this->_currentBullet]->setSpeed(50.0f);
            this->_bullets[this->_currentBullet]->_timeReload = 0.05f;
        }
        if (this->_weapon == 1) {
            this->_bullets[this->_currentBullet]->setRange(1000.0f);
            this->_bullets[this->_currentBullet]->setDistance(1000.0f);
            this->_bullets[this->_currentBullet]->setSpeed(30.0f);
            this->_bullets[this->_currentBullet]->_timeReload = 0.5f;
        }
        if (this->_weapon == 2) {
            this->_bullets[this->_currentBullet]->setRange(800.0f);
            this->_bullets[this->_currentBullet]->setDistance(800.0f);
            this->_bullets[this->_currentBullet]->setSpeed(18.0f);
            this->_bullets[this->_currentBullet]->_timeReload = 0.3f;
        }
        if (this->_weapon == 3) {
            this->_bullets[this->_currentBullet]->setRange(5000.0f);
            this->_bullets[this->_currentBullet]->setDistance(5000.0f);
            this->_bullets[this->_currentBullet]->setSpeed(50.0f);
            this->_bullets[this->_currentBullet]->_timeReload = 0.2f;
        }
        float somme = std::abs((tmpC.x - tmpV.x)) + std::abs((tmpC.y - tmpV.y));
        res.x = (tmpC.x - tmpV.x) / somme * this->_bullets[this->_currentBullet]->getSpeed();
        res.y = (tmpC.y - tmpV.y) / somme * this->_bullets[this->_currentBullet]->getSpeed();
        this->_bullets[this->_currentBullet]->setDirection(res);
        this->_bullets[this->_currentBullet]->setSkin(this->_weapon);
        this->_currentBullet++;
        this->_currentBullet = (this->_currentBullet == this->_shoot) ? 0 : this->_currentBullet;
        this->_shootClock.restart();
    }
}

void Player::updateGlow()
{
    if (this->_glowClock.getElapsedTime().asSeconds() >= 0.1) {
        this->_glows[this->_currentGlow]->setPosition(this->getPosition());
        this->_glows[this->_currentGlow]->setAngle(this->getAngle());
        if (this->_rollClock.getElapsedTime().asSeconds() >= 10.0f - this->_glow * 0.1) {
            this->_glows[this->_currentGlow]->setDisplay(true);
            this->_glows[this->_currentGlow]->swapSkin(this->_soundSpeed);
        }
        this->_currentGlow++;
        this->_currentGlow = (this->_currentGlow == this->_glow) ? 0 : this->_currentGlow;
        this->_glowClock.restart();
    }
}

void Player::rollBackSpell()
{
    static size_t rollTurn = 0;

    if ((sf::Keyboard::isKeyPressed((sf::Keyboard::Key)this->_keyRollBack) || sf::Joystick::isButtonPressed(0, 2)) && !this->_rollback && this->_rollClock.getElapsedTime().asSeconds() >= 10.0f) {
        this->_rollback = true;
        this->_rollSound.play();
    }
    if (this->_rollback) {
        if (this->_glowClock.getElapsedTime().asSeconds() >= 0.08) {
            this->_currentGlow = (this->_currentGlow == 0) ? this->_glow - 1 : this->_currentGlow - 1;
            this->setPosition(this->_glows[this->_currentGlow]->getPosition());
            this->setAngle(this->_glows[this->_currentGlow]->getAngle());
            this->_glows[this->_currentGlow]->setDisplay(false);
            
            rollTurn++;
            if (rollTurn == this->_glow) {
                this->_rollback = false;
                this->_rollClock.restart();
                rollTurn = 0;
            }
        }
    }
}

void Player::changeWeapon()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) || sf::Joystick::isButtonPressed(0, 4)) && this->_weaponClock.getElapsedTime().asSeconds() >= 0.75f) {
        this->_weapon = (this->_weapon == 3) ? 0 : this->_weapon + 1;
        this->_switchSound.play();
        this->_weaponClock.restart();
    }
}

void Player::updateQuote()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        this->_quoteSound[0]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        this->_quoteSound[1]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        this->_quoteSound[2]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        this->_quoteSound[3]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        this->_quoteSound[4]->play();
}

void Player::updateSpeed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && this->_speedClock.getElapsedTime().asSeconds() >= 10.0f) {
        this->_soundSpeed = true;
        this->_speedSound.play();
        this->_speedClock.restart();
    }
    if (this->_soundSpeed == true && this->_speedClock.getElapsedTime().asSeconds() >= 3.0f) {
        this->_soundSpeed = false;
    }
}

void Player::updateEnnemy()
{
    sf::Vector2f position;
    
    if (this->_stageOn == false && this->isFightOn() == false) {
       size_t i = 0;
        for (auto ennemy : this->_ennemies) {
            if (i < (10 + ennemy->getLvl()))
                ennemy->setDisplay(true);
            i++;
        }
   }

    if (this->isFightOn() == false && this->_stageOn == true) {
        this->_stageOn = false;
        size_t i = 0;
        for (auto ennemy : this->_ennemies) {
            ennemy->setFightOn(true);
            ennemy->addLvl();
            if (i < (5 + ennemy->getLvl())) {
                ennemy->setDisplay(true);
                ennemy->setFightOn(true);
            }
            else
                ennemy->setFightOn(false);
            i++;
        }
    }
    for (auto ennemy : this->_ennemies) {
        if (ennemy->getDisplay())
            if (this->ennemyKilled(ennemy->getPosition(), ennemy->getHitbox())) { // colide a missile
                ennemy->setDisplay(false);
                ennemy->setFightOn(false);
            }
        if (ennemy->_iaType == 0) {
            ennemy->setAngle(this->getPosition());
            ennemy->_target = this->getPosition();
        }
    }
    if (this->isFightOn() == false && this->_stageOn == true) {
        this->_stageOn = false;
        for (auto ennemy : this->_ennemies) {
            ennemy->addLvl();
        }
    }
}

bool Player::isFightOn()
{

    for (auto ennemy : this->_ennemies) {
        if (ennemy->getFightOn() == true)
            return true;
    }
    return false;
}

bool Player::ennemyKilled(sf::Vector2f const &position, sf::IntRect const &hitbox) const
{
    sf::IntRect rect = {(int)position.x - 25, (int)position.y - 25, (int)hitbox.width, (int)hitbox.height};

    for (auto missile : this->_bullets)
        if (rect.contains((int)missile->getPosition().x, (int)missile->getPosition().y) && missile->getDisplay()) {
            missile->setDisplay(false);
            return true;
        }
    return false;
}

void Player::checkAlive()
{
    sf::IntRect rect;

    for (auto ennemy : this->_ennemies) {
        rect.left = (int)ennemy->getPosition().x - 25;
        rect.top = (int)ennemy->getPosition().y - 25;
        rect.width = (int)ennemy->getHitbox().width;
        rect.height = (int)ennemy->getHitbox().height;
        if (rect.contains((int)this->getPosition().x, (int)this->getPosition().y) && ennemy->getDisplay() && this->_stageOn) {
            this->setDisplay(false);
            this->_alive = false;
        }
    }
}

void Player::setForward(size_t forward)
{
    this->_keyForward = forward;
}

void Player::setBackward(size_t backward)
{
    this->_keyBackward = backward;
}

void Player::setRight(size_t right)
{
    this->_keyRight = right;
}

void Player::setLeft(size_t left)
{
    this->_keyLeft = left;
}

void Player::setDash(size_t dash)
{
    this->_keyDash = dash;
}

void Player::setRollBack(size_t rollBack)
{
    this->_keyRollBack = rollBack;
}

size_t Player::getForward() const
{
    return this->_keyForward;
}

size_t Player::getBackward() const
{
    return this->_keyBackward;
}

size_t Player::getRight() const
{
    return this->_keyRight;
}

size_t Player::getLeft() const
{
    return this->_keyLeft;
}

size_t Player::getDash() const
{
    return this->_keyDash;
}

size_t Player::getRollBack() const
{
    return this->_keyRollBack;
}

void Player::readSave()
{
    std::ifstream file(".ashersave");
    std::string lvl;

    std::getline(file, lvl);
    std::cout << "lvl = " << lvl << std::endl;
    file.close();
}

void Player::writeSave()
{
    std::string save = "echo " + std::to_string(this->_ennemies[0]->getLvl()) + " > .ashersave";
    system(save.c_str());
}