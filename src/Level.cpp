#include "Level.h"

#include "PlayerThief.h"
Level::Level(int width, int height, float gravity, std::vector<Object> contents)
    : height(height), width(width), gravity(gravity), contents(contents) {}

void Level::addObject(Object object) { this->contents.push_back(object); }

Level::~Level() { this->contents.clear(); }