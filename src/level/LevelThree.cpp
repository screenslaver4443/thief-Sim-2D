#include "LevelThree.h"
#include <iostream>

LevelThree::LevelThree() : Level(800, 600), bossActivated(false)
{
    if (!employeeTexture.loadFromFile("sprites/employee.png"))
        std::cout << "Failed to load employee.png\n";
    if (!securityTexture.loadFromFile("sprites/security.png"))
        std::cout << "Failed to load security.png\n";
    if (!bossTexture.loadFromFile("sprites/boss.png"))
        std::cout << "Failed to load boss.png\n";

    employeeSprite.setTexture(employeeTexture);
    securitySprite.setTexture(securityTexture);
    bossSprite.setTexture(bossTexture);

    employeeSprite.setScale(1.5f, 1.5f);
    securitySprite.setScale(1.5f, 1.5f);
    bossSprite.setScale(1.5f, 1.5f);
}

void LevelThree::load()
{
    std::cout << "Level 3 loaded — Employee, Security, Boss active\n";

    employee.setPosX(300);
    employee.setPosY(400);
    security.setPosX(500);
    security.setPosY(400);
    boss.setPosX(700);
    boss.setPosY(400);

    employeeSprite.setPosition(300, 400);
    securitySprite.setPosition(500, 400);
    bossSprite.setPosition(700, 400);
}

void LevelThree::update(float deltaTime, PlayerThief &player)
{
    employee.update(deltaTime, player);
    security.chase(player);

    if (!bossActivated && boss.intersects(player))
    {
        bossActivated = true;
        std::cout << "Boss activated — moving toward security!\n";
    }

    if (bossActivated)
        boss.update(security);
}

void LevelThree::draw(sf::RenderWindow &window)
{
    window.draw(employeeSprite);
    window.draw(securitySprite);
    window.draw(bossSprite);
}
