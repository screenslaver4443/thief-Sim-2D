#ifndef PLAYERTHIEF_H
#define PLAYERTHIEF_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class PlayerThief : public Object
{
private:
    int health;
    bool justHealed = false;
    float speed = 200.0f; // default player movement speed (px/sec)

public:
    PlayerThief();
    void takeDamage(int amount);
    void setHealth(int h);
    int getHealth() const;

    sf::FloatRect getBounds() const;
    bool intersects(const Object &other) const;
    void setJustHealed(bool v);
    bool getJustHealed() const;
    void setSpeed(float s);
    float getSpeed() const;
};

#endif
