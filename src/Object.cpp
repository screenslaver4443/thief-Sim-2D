#include "Object.h"

Object::Object() : hasGravity(false), posX(0), posY(0), sizeX(0), sizeY(0) {}

Object::Object(bool gravity, float X, float Y, float sizeX, float sizeY)
    : hasGravity(gravity), posX(X), posY(Y), sizeX(sizeX), sizeY(sizeY) {}

void Object::setPosX(float newX) { this->posX = newX; }
void Object::setPosY(float newY) { this->posY = newY; }

void Object::handleGravity(float gravity) {
  if (gravity) this->posY -= gravity;
}

void Object::moveX(float X) { this->posX += X; }
void Object::moveY(float Y) { this->posY += Y; }

float Object::getX() { return this->posX; }

float Object::getY() { return this->posY; }