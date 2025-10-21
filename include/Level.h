#ifndef LEVEL_H
#define LEVEL_H

#include "Object.h"
#include <vector>

class Level
{
private:
    int width;
    int height;
    std::vector<Object> elements;

public:
    Level(int width, int height, std::vector<Object> contents);
    void setWidth(int);
    void setHeight(int);
    int getWidth() const;
    int getHeight() const;
};

#endif
