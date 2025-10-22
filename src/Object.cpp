#include "Object.h"
// core object code to inherit

Object::Object()
    : posX(0), posY(0), sizeX(32), sizeY(32), gravity(false), collision(false) {}

Object::Object(float x, float y, float width, float height)
    : posX(x), posY(y), sizeX(width), sizeY(height), gravity(false), collision(false) {}

void Object::setPosition(float x, float y)
{
    posX = x;
    posY = y;
}
sf::Vector2f Object::getPosition() const { return sf::Vector2f(posX, posY); }

void Object::setSize(float w, float h)
{
    sizeX = w;
    sizeY = h;
}
sf::Vector2f Object::getSize() const { return sf::Vector2f(sizeX, sizeY); }

void Object::setPosX(float x) { posX = x; }
void Object::setPosY(float y) { posY = y; }
float Object::getPosX() const { return posX; }
float Object::getPosY() const { return posY; }
