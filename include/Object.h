#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object
{
protected:
    float posX, posY;
    float sizeX, sizeY;
    bool gravity;
    bool collision;

public:
    Object();
    Object(float x, float y, float width, float height);
    virtual ~Object() = default;

    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSize(float w, float h);
    sf::Vector2f getSize() const;

    void setPosX(float x);
    void setPosY(float y);
    float getPosX() const;
    float getPosY() const;
};

#endif
