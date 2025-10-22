#ifndef LEVEL_H
#define LEVEL_H
// Base Level class we will use in LevelOne, LevelTwo, and LevelThree
// this way it is less repetitive :3

#include <vector>
#include "Object.h"
#include <SFML/Graphics.hpp>

class PlayerThief;

class Level
{
protected:
    int width;
    int height;
    std::vector<Object *> elements;

public:
    Level();
    Level(int w, int h);
    ~Level() = default;
    void setWidth(int w);
    void setHeight(int h);

    int getWidth() const;
    int getHeight() const;
    virtual void load();

    virtual void update(float deltaTime, PlayerThief &player) {}
    virtual void draw(sf::RenderWindow &window) {}
    virtual bool hasEmployee() const { return false; }
};

#endif
#ifndef LEVEL_H

// upload errors: different people working at same time led to merge clahes, so
// this was the fix
#define LEVEL_H

#include <vector>
#include "Object.h"
#include <SFML/Graphics.hpp>

class PlayerThief;

class Level
{
protected:
    int width;
    int height;
    std::vector<Object *> elements;

public:
    Level();
    Level(int w, int h);
    ~Level() = default;
    void setWidth(int w);
    void setHeight(int h);

    int getWidth() const;
    int getHeight() const;
    virtual void load();
    virtual void update(float deltaTime, PlayerThief &player) {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif
