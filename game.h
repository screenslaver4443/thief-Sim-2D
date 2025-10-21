//
// Created by Nikolai Pesudovs on 14/10/2025.
//
#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include "Object.h"
#include "Level.h"

#include <SFML/Graphics.hpp>
#include "PlayerThief.h"
#include <iostream>

enum class GameState
{
    MAIN_MENU,
    LEVEL,
    VICTORY
};

class Game
{
private:
    sf::RenderWindow &window;
    GameState state;

    // erm sprite stuff
    // tests if they all load in and pukks them from sprites folder
    sf::Texture playerTex, buttonTex, heartTex, diamondTex;
    sf::Sprite player, button, heart, diamond;

    // life system (ie 3 is max health)
    sf::Sprite hearts[3];
    sf::Sprite menuButton;

    PlayerThief playerObj;
    sf::Clock clock;

    // gang we cant do arial I dont have the file :(
    sf::Font font;
    sf::Text menuText;

    // tracks levels beaten in a session :3
    int levelsBeaten;
    sf::Sprite diamondIcon;
    sf::Text diamondCount;

    // sussy baka system
    int suspicion;
    int heartsRemaining;
    float suspicionTimer;

    // sound bar (gang I made it scrollable)
    float soundLevel;
    sf::RectangleShape soundBarBG, soundBar;

    // levelzzzzz
    sf::Sprite levelButtons[3];
    sf::Text levelText[3];

public:
    Game(sf::RenderWindow &win);
    void run();

private:
    void processEvents();
    void update();
    void render();
};

#endif // GAME_H
