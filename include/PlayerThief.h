#ifndef PLAYERTHIEF_H
#define PLAYERTHIEF_H

#include "Object.h"
#include <SFML/Graphics.hpp>

class PlayerThief : public Object
{
private:
    int health;

public:
    PlayerThief();
    void takeDamage(int amount);
    void setHealth(int h);
    int getHealth() const;

    sf::FloatRect getBounds() const;
    bool intersects(const Object &other) const;
};

#endif
