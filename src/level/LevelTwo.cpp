#include "LevelTwo.h"
#include <SFML/Graphics.hpp>

LevelTwo::LevelTwo() : Level(900, 700, 0.0f, {}) {}

void LevelTwo::setup()
{

    backgroundColor = sf::Color(220, 240, 255);
    diamondPosition = {700.f, 300.f};
    suspicionRate = 1.5f;
}
