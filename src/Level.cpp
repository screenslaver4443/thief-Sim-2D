#include "Level.h"

#include "PlayerThief.h"

Level::Level(int width, int height, std::vector<Object> contents)
    : width(width), height(height), elements(contents)
{
}

void Level::setWidth(int w) { width = w; }
void Level::setHeight(int h) { height = h; }

int Level::getWidth() const { return width; }
int Level::getHeight() const { return height; }
