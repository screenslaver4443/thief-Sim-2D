#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Object.h"

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
};

#endif
