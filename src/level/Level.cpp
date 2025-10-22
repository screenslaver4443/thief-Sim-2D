#include "Level.h"
#include <iostream>
// Base Level we will use in LevelOne, LevelTwo, and LevelThree
// this way it is less repetitive :3

Level::Level() : width(800), height(600) {}

Level::Level(int w, int h) : width(w), height(h) {}

void Level::setWidth(int w) { width = w; }
void Level::setHeight(int h) { height = h; }

int Level::getWidth() const { return width; }
int Level::getHeight() const { return height; }

void Level::load()
{
    std::cout << "Loading base Level with dimensions: "
              << width << "x" << height << std::endl;
}
