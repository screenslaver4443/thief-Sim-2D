#include "LevelOne.h"
#include <SFML/Graphics.hpp>
#include <iostream>

LevelOne::LevelOne() : Level(800, 600)
{
    std::cout << "Level 1 created with dimensions 800x600\n";
}

void LevelOne::load()
{
    std::cout << "Loading Level 1 assets and entities...\n";
}

void LevelOne::update(float deltaTime, PlayerThief &player)
{
    // Base level currently does not have interactive entities.
    (void)deltaTime;
    (void)player;
}

void LevelOne::draw(sf::RenderWindow &window)
{
    // Nothing to draw specifically for LevelOne; Game renders shared UI and player
    (void)window;
}
