#include "LevelTwo.h"
#include <iostream>

LevelTwo::LevelTwo() : Level(800, 600)
{
    // Load textures
    if (!allyTexture.loadFromFile("sprites/ally.png"))
        std::cout << "Failed to load ally.png\n";
    if (!employeeTexture.loadFromFile("sprites/employee.png"))
        std::cout << "Failed to load employee.png\n";
    if (!ownerTexture.loadFromFile("sprites/owner.png"))
        std::cout << "Failed to load owner.png\n";

    // Attach textures to sprites
    allySprite.setTexture(allyTexture);
    employeeSprite.setTexture(employeeTexture);
    ownerSprite.setTexture(ownerTexture);

    // Scale (optional)
    allySprite.setScale(1.5f, 1.5f);
    employeeSprite.setScale(1.5f, 1.5f);
    ownerSprite.setScale(1.5f, 1.5f);
}

void LevelTwo::load()
{
    std::cout << "Level 2 loaded — Ally, Employee, Owner active\n";

    // Set positions
    ally.setPosX(200);
    ally.setPosY(400);
    employee.setPosX(500);
    employee.setPosY(400);
    owner.setPosX(650);
    owner.setPosY(400);

    allySprite.setPosition(200, 400);
    employeeSprite.setPosition(500, 400);
    ownerSprite.setPosition(650, 400);
}

void LevelTwo::update(float deltaTime, PlayerThief &player)
{
    // Ally heals player when touched
    if (ally.intersects(player))
    {
        player.setHealth(100);
        std::cout << "Healed to full health!\n";
    }

    // Employee increases suspicion
    employee.update(deltaTime, player);

    // Owner detection radius
    sf::FloatRect playerRect(player.getPosX(), player.getPosY(), 32, 32);
    if (owner.detectsPlayer(playerRect))
    {
        std::cout << "Owner caught you! Scene change triggered.\n";
        // TODO: trigger level fail or scene change
    }
}

void LevelTwo::draw(sf::RenderWindow &window)
{
    window.draw(allySprite);
    window.draw(employeeSprite);
    window.draw(ownerSprite);
}
