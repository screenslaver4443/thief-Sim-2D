#include "PlayerThief.h"

PlayerThief::PlayerThief() : health(100) {}

void PlayerThief::takeDamage(int amount)
{
    health -= amount;
    if (health < 0)
        health = 0;
}

void PlayerThief::setHealth(int h)
{
    health = h;
    if (health < 0)
        health = 0;
    if (health > 100)
        health = 100;
}

int PlayerThief::getHealth() const
{
    return health;
}

sf::FloatRect PlayerThief::getBounds() const
{
    return sf::FloatRect(posX, posY, sizeX, sizeY);
}

bool PlayerThief::intersects(const Object &other) const
{
    sf::Vector2f otherPos = other.getPosition();
    sf::Vector2f otherSize = other.getSize();
    sf::FloatRect otherBounds(otherPos.x, otherPos.y, otherSize.x, otherSize.y);
    return getBounds().intersects(otherBounds);
}

void PlayerThief::setJustHealed(bool v) { justHealed = v; }

bool PlayerThief::getJustHealed() const { return justHealed; }

void PlayerThief::setSpeed(float s) { speed = s; }

float PlayerThief::getSpeed() const { return speed; }
