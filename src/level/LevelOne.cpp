#include "LevelOne.h"
#include <SFML/Graphics.hpp>

LevelOne::LevelOne() : Level(900, 700, 0.0f, {}) {}

void LevelOne::setup()
{

    backgroundColor = sf::Color(245, 245, 245);

    diamondPosition = {600.f, 400.f};

    suspicionRate = 1.0f;
}
