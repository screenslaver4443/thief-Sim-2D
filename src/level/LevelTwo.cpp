#include "LevelTwo.h"
#include <iostream>
// second level logic

LevelTwo::LevelTwo() : Level(800, 600)
{
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

    const float npcScale = 0.05f;
    allySprite.setScale(npcScale, npcScale);
    employeeSprite.setScale(npcScale, npcScale);
    ownerSprite.setScale(npcScale, npcScale);

    sf::FloatRect aBounds = allySprite.getLocalBounds();
    allySprite.setOrigin(aBounds.width / 2.f, aBounds.height / 2.f);
    sf::FloatRect eBounds = employeeSprite.getLocalBounds();
    employeeSprite.setOrigin(eBounds.width / 2.f, eBounds.height / 2.f);
    sf::FloatRect oBounds = ownerSprite.getLocalBounds();
    ownerSprite.setOrigin(oBounds.width / 2.f, oBounds.height / 2.f);

    ally.setSize(allyTexture.getSize().x * npcScale, allyTexture.getSize().y * npcScale);
    employee.setSize(employeeTexture.getSize().x * npcScale, employeeTexture.getSize().y * npcScale);
    owner.setSize(ownerTexture.getSize().x * npcScale, ownerTexture.getSize().y * npcScale);
}

void LevelTwo::load()
{
    std::cout << "Level 2 loaded — Ally, Employee, Owner active\n";

    ally.setPosX(200);
    ally.setPosY(400);
    employee.setPosX(760);
    employee.setPosY(200);
    owner.setPosX(500);
    owner.setPosY(400);

    owner.setupZone(120, 120);
    owner.setZoneCenter(owner.getPosX(), owner.getPosY());
    allySprite.setPosition(200, 400);
    // employee moved to top area, when he was in way it was confudign :3
    employeeSprite.setPosition(employee.getPosX(), employee.getPosY());
    ownerSprite.setPosition(owner.getPosX(), owner.getPosY());

    ally.setIsAlive(true);
    ally.setHealth(100);

    ally.setSkill(2);
    employee.setIsAlive(true);
    employee.setHealth(100);

    employee.resetSuspicion();
    owner.setIsAlive(true);
    owner.setHealth(100);
}

void LevelTwo::update(float deltaTime, PlayerThief &player)
{

    if (ally.getIsAlive())
    {
        sf::FloatRect allyRect = allySprite.getGlobalBounds();
        if (allyRect.intersects(player.getBounds()))
            ally.healPlayer(player);

        ally.updateCooldown(deltaTime);
    }

    // Employee increases suspicion when taking too
    // mucj time
    employee.update(deltaTime, player);

    sf::FloatRect playerRect = player.getBounds();
    if (owner.getIsAlive() && owner.detectsPlayer(playerRect))
    {
        std::cout << "Owner caught you! Scene change triggered.\n";
        player.setHealth(0);
    }

    // Sync sprites with entity positions
    // took me waaaaaaay to long to get right
    if (ally.getIsAlive())
        allySprite.setPosition(ally.getPosX(), ally.getPosY());
    if (employee.getIsAlive())
        employeeSprite.setPosition(employee.getPosX(), employee.getPosY());
    if (owner.getIsAlive())
        ownerSprite.setPosition(owner.getPosX(), owner.getPosY());
}

void LevelTwo::draw(sf::RenderWindow &window)
{
    window.draw(allySprite);
    window.draw(employeeSprite);
    window.draw(ownerSprite);
    if (owner.getIsAlive())
        window.draw(owner.getZone());
}
