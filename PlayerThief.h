#ifndef PLAYERTHIEF_H
#define PLAYERTHIEF_H
#include <SFML/Graphics.hpp>

#include "Criminal.h"

class PlayerThief : Criminal
{
private:
    int Health;
    int StolenGoods;

    // gui
    sf::RectangleShape shape;

public:
    void steal();
    void setStoleGoods(int);
    void attack();
    void takeDamage(int);
    void moveLeft();
    void moveRight();
    void jump();
    // gui
    PlayerThief()
    {
        shape.setSize(sf::Vector2f(50, 100));
        shape.setFillColor(sf::Color::Cyan);
        shape.setPosition(100, 400);
    }
};

#endif
