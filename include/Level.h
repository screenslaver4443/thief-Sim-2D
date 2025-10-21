#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.h"

// Base Level classss which we gonna use in LevelOne, LevelTwo, and LevelThree
class Level
{
private:
    int width;
    int height;

public:
    Level(int width, int height, float gravity, std::vector<Object> contents);
    Level() = default;

    void setWidth(int);
    void setHeight(int);
    int getWidth() const;
    int getHeight() const;

    sf::Color backgroundColor;
    sf::Vector2f diamondPosition;
    float suspicionRate;

    virtual void setup() = 0;
    virtual ~Level() = default;
};

#endif // LEVEL_H
