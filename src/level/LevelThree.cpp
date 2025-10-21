#include "LevelThree.h"
#include <SFML/Graphics.hpp>

LevelThree::LevelThree() : Level(900, 700, 0.0f, {}) {}

void LevelThree::setup()
{

    backgroundColor = sf::Color(255, 230, 230);

    diamondPosition = {750.f, 200.f};

    suspicionRate = 2.0f;
}
