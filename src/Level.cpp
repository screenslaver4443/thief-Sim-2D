#include "Level.h"

#include "PlayerThief.h"

Level::Level(int width, int height, float gravity, std::vector<Object> contents)
    : width(width), height(height), gravity(gravity), elements(contents) // correct order
{
}

void Level::setWidth(int w) { width = w; }
void Level::setHeight(int h) { height = h; }

int Level::getWidth() const { return width; }
int Level::getHeight() const { return height; }
