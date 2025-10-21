//
// Created by Nikolai Pesudovs on 14/10/2025.
//
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 700), "Thief Sim 2D");
    window.setFramerateLimit(60);

    Game game(window);
    game.run();

    return 0;
}
