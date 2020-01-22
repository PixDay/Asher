/*
** Merline, 2019
** Ennemy.cpp
** File description:
** Adrien Colombier
*/

#include "Ennemy.hpp"

Ennemy::Ennemy()
{
    sf::Vector2f scale = {0.4f, -0.4f};
    sf::Vector2f origin = {64.0f, 71.0f};

    this->_iaType = std::rand() % 4;
    this->_lvl = 1;
    this->_fightOn = false;
    this->setDisplay(true);
    this->setScale(scale);
    this->setOrigin(origin);
    this->setDisplay(false);
    if (this->_iaType == 0)
        this->setIa0();
    if (this->_iaType == 1) {
        this->setIa1();
    }
    if (this->_iaType == 2)
        this->setIa2();
    if (this->_iaType == 3)
        this->setIa3();
}

void Ennemy::draw()
{
}

void Ennemy::autoManage()
{
    if (this->_fightOn == true) {
        if (this->getPosition().x < 0 && this->getPosition().y < 0)
            this->setDisplay(false);
        else {
            if (this->_iaType == 0) {
                this->Ia0();
            }
            else if (this->_iaType == 1) {
                this->Ia1();
            }
            else if (this->_iaType == 2) {
                this->Ia2();
            }
            else if (this->_iaType == 3) {
                this->Ia3();
            }
        }
    }
}

size_t Ennemy::getLvl() const
{
    return this->_lvl;
}

bool Ennemy::getFightOn() const
{
    return this->_fightOn;
}

void Ennemy::addLvl()
{
    this->_lvl++;
}

void Ennemy::setFightOn(bool const &fight)
{
    this->_fightOn = fight;
}

void Ennemy::setIa0()
{
    sf::Vector2f position;
    
    position.x = (std::rand() % 4000) + 1920;
    position.y = (std::rand() % 3000) + 1080;
    this->setPosition(position);
    this->setTexture("image/ennemy/ennemy.png");
    this->setSpeed(2.0f);
}

void Ennemy::setIa1()
{
    sf::Vector2f position;
    float angle = 0.0f;

    position.x = (std::rand() % 1920);
    position.y = (std::rand() % 1080);
    this->_target.x = ((static_cast<float>(std::rand() % 100)) / 100.0f);
    this->_target.y = 1.0f - this->_target.x;
    angle = atanf(this->_target.x / this->_target.y);
    angle = angle * 180  / M_PI;
    angle = (this->_target.x < 0) ? -angle : angle + 2 * (90.0f - angle);
    this->setAngle(angle);
    this->setPosition(position);
    this->setTexture("image/ennemy/ennemy1.png");
    this->setSpeed(static_cast<float>(std::rand() % 4) + 5.0f);
}

void Ennemy::setIa2()
{
    sf::Vector2f position;
    
    position.x = (std::rand() % 4000) + 1920;
    position.y = (std::rand() % 3000) + 1080;
    this->_target.x = std::rand() % 1920;
    this->_target.y = std::rand() % 1080;
    this->setPosition(position);
    this->setTexture("image/ennemy/ennemy2.png");
    this->setSpeed(8.0f);
}

void Ennemy::setIa3()
{
    sf::Vector2f position;
    sf::Vector2f p0;
    sf::Vector2f p1;
    sf::Vector2f p2;
    sf::Vector2f p3;

    position.x = std::rand() % 1920;
    position.y = std::rand() % 1080;
    this->_rayon = (std::rand() % 400) + 100;
    p0.x = position.x; p0.y = position.y - _rayon;
    p1.x = position.x - _rayon; p1.y = position.y;
    p2.x = position.x; p2.y = position.y + _rayon;
    p3.x = position.x + _rayon; p3.y = position.y;
    this->_losangePoint = 0;
    this->_losange.push_back(p0);
    this->_losange.push_back(p1);
    this->_losange.push_back(p2);
    this->_losange.push_back(p3);
    this->_target = p0;
    this->setPosition(position);
    this->setTexture("image/ennemy/ennemy3.png");
    this->setSpeed(5.0f);
}

void Ennemy::Ia0()
{
    sf::Vector2f position = this->getPosition();
    position.x = (position.x > _target.x) ? position.x + -1 * this->getSpeed() : position.x + 1 * this->getSpeed();
    position.y = (position.y > _target.y) ? position.y + -1 * this->getSpeed() : position.y + 1 * this->getSpeed();
    position.x = (std::abs(position.x - _target.x) <= (this->getSpeed())) ? _target.x : position.x; 
    position.y = (std::abs(position.y - _target.y) <= (this->getSpeed())) ? _target.y : position.y; 
    this->setPosition(position);
}

void Ennemy::Ia1()
{
    sf::Vector2f position = this->getPosition();
    float angle = this->getAngle();

    position.x += this->_target.x * this->getSpeed();
    position.y += this->_target.y * this->getSpeed();
    if (position.x <= 0.0f || position.x >= 1920.0f) {
        this->_target.x *= -1;
        angle = 360.0f - angle;
        angle -= (angle >= 360) ? 360 : 0;
        this->setAngle(angle);
    }
    if (position.y <= 0.0f || position.y >= 1080.0f) {
        this->_target.y *= -1;
        angle = 180.0f - angle;
        angle -= (angle >= 360) ? 360 : 0;
        this->setAngle(angle);
    }
    this->setPosition(position);
}

void Ennemy::Ia2()
{
    sf::Vector2f position = this->getPosition();

    if (position.x == this->_target.x && position.y == _target.y) {
        this->_target.x = std::rand() % 1920;
        this->_target.y = std::rand() % 1080;
    }
    position.x = (position.x > _target.x) ? position.x + -1 * this->getSpeed() : position.x + 1 * this->getSpeed();
    position.y = (position.y > _target.y) ? position.y + -1 * this->getSpeed() : position.y + 1 * this->getSpeed();
    position.x = (std::abs(position.x - _target.x) <= (this->getSpeed())) ? _target.x : position.x; 
    position.y = (std::abs(position.y - _target.y) <= (this->getSpeed())) ? _target.y : position.y; 
    this->setPosition(position);
    this->setAngle(this->_target);
}

void Ennemy::Ia3()
{
    sf::Vector2f position = this->getPosition();

    if (position.x == this->_target.x && position.y == _target.y) {
        this->_losangePoint = (this->_losangePoint == 3) ? 0 : this->_losangePoint + 1;
        this->_target = this->_losange[this->_losangePoint];
    }
    position.x = (position.x > _target.x) ? position.x + -1 * this->getSpeed() : position.x + 1 * this->getSpeed();
    position.y = (position.y > _target.y) ? position.y + -1 * this->getSpeed() : position.y + 1 * this->getSpeed();
    position.x = (std::abs(position.x - _target.x) <= (this->getSpeed())) ? _target.x : position.x; 
    position.y = (std::abs(position.y - _target.y) <= (this->getSpeed())) ? _target.y : position.y; 
    this->setPosition(position);
    this->setAngle(this->_target);
}