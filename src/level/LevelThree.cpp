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

    // Match player size
    const float npcScale = 0.05f;
    employeeSprite.setScale(npcScale, npcScale);
    securitySprite.setScale(npcScale, npcScale);
    bossSprite.setScale(npcScale, npcScale);

    // center sprite origins
    sf::FloatRect eBounds = employeeSprite.getLocalBounds();
    employeeSprite.setOrigin(eBounds.width / 2.f, eBounds.height / 2.f);
    sf::FloatRect sBounds = securitySprite.getLocalBounds();
    securitySprite.setOrigin(sBounds.width / 2.f, sBounds.height / 2.f);
    sf::FloatRect bBounds = bossSprite.getLocalBounds();
    bossSprite.setOrigin(bBounds.width / 2.f, bBounds.height / 2.f);

    // set object sizes to match sprite visuals (scaled)
    employee.setSize(employeeTexture.getSize().x * npcScale, employeeTexture.getSize().y * npcScale);
    security.setSize(securityTexture.getSize().x * npcScale, securityTexture.getSize().y * npcScale);
    boss.setSize(bossTexture.getSize().x * npcScale, bossTexture.getSize().y * npcScale);
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
    // place boss at top-middle of the screen
    boss.setPosX(400);
    boss.setPosY(50);
    bossSprite.setPosition(boss.getPosX(), boss.getPosY());

    // Ensure boss is initially inactive
    bossActivated = false;

    // revive entities in case of replays
    employee.setIsAlive(true);
    employee.setHealth(100);
    employee.resetSuspicion();
    security.setIsAlive(true);
    security.setHealth(100);
    boss.setIsAlive(true);
    boss.setHealth(100);
    // give boss a skill level (affects the temporary buff strength/duration)
    boss.setSkill(2);
}

void LevelThree::update(float deltaTime, PlayerThief &player)
{
    employee.update(deltaTime, player);
    security.chase(player, deltaTime);

    // Boss no longer targets security; boss remains idle at top-middle.
    // If we ever want a more complex behavior, implement it here.

    // Boss touch: if player touches boss, apply a temporary speed buff based on boss skill
    if (boss.getIsAlive() && player.intersects(boss))
    {
        int skill = boss.getSkill();
        float multiplier = 1.0f + 0.5f * static_cast<float>(skill); // e.g. skill=2 -> 2.0x
        float duration = 5.0f * static_cast<float>(skill);          // longer with higher skill
        std::cout << "Player touched boss: applying speed buff x" << multiplier << " for " << duration << "s\n";
        player.applySpeedBuff(multiplier, duration);
        boss.setIsAlive(false);
        boss.setHealth(0);
    }

    // Sync sprites with entity positions (always sync to avoid visual lag)
    employeeSprite.setPosition(employee.getPosX(), employee.getPosY());
    securitySprite.setPosition(security.getPosX(), security.getPosY());
    bossSprite.setPosition(boss.getPosX(), boss.getPosY());
}

void LevelThree::draw(sf::RenderWindow &window)
{
    window.draw(employeeSprite);
    window.draw(securitySprite);
    window.draw(bossSprite);
}
