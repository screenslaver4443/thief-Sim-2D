#include "Object.h"

Object::Object(bool gravity, float x, float y, float sizex, float sizey)
    : hasGravity(gravity), posX(x), posY(y), sizeX(sizex), sizeY(sizey)
{
}

void Object::setPosX(float x)
{
    posX = x;
}

void Object::setPosY(float y)
{
    posY = y;
}

float Object::getPosX()
{
    return posX;
}

float Object::getPosY()
{
    return posY;
}

float Object::getSizeX()
{
    return sizeX;
}

float Object::getSizeY()
{
    return sizeY;
}
