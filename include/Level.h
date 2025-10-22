#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Object.h"
#include <SFML/Graphics.hpp>

class PlayerThief;

// Base Level class we will use in LevelOne, LevelTwo, and LevelThree
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
    // Optional per-level update/draw hooks. Default no-op so older levels
    // that don't override them will continue to work.
    virtual void update(float deltaTime, PlayerThief &player) {}
    virtual void draw(sf::RenderWindow &window) {}
    // Does this level contain an Employee (affects global suspicion)?
    virtual bool hasEmployee() const { return false; }
};

#endif
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Object.h"
#include <SFML/Graphics.hpp>

class PlayerThief;

// Base Level class we will use in LevelOne, LevelTwo, and LevelThree
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
    // Optional per-level update/draw hooks. Default no-op so older levels
    // that don't override them will continue to work.
    virtual void update(float deltaTime, PlayerThief &player) {}
    virtual void draw(sf::RenderWindow &window) {}
};

#endif
