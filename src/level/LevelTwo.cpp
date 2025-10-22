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
    // Match player size (player scaled to 0.05f in Game)
    const float npcScale = 0.05f;
    allySprite.setScale(npcScale, npcScale);
    employeeSprite.setScale(npcScale, npcScale);
    ownerSprite.setScale(npcScale, npcScale);

    // center sprite origins so position corresponds to sprite center
    sf::FloatRect aBounds = allySprite.getLocalBounds();
    allySprite.setOrigin(aBounds.width / 2.f, aBounds.height / 2.f);
    sf::FloatRect eBounds = employeeSprite.getLocalBounds();
    employeeSprite.setOrigin(eBounds.width / 2.f, eBounds.height / 2.f);
    sf::FloatRect oBounds = ownerSprite.getLocalBounds();
    ownerSprite.setOrigin(oBounds.width / 2.f, oBounds.height / 2.f);

    // set object sizes to match sprite visuals (scaled)
    ally.setSize(allyTexture.getSize().x * npcScale, allyTexture.getSize().y * npcScale);
    employee.setSize(employeeTexture.getSize().x * npcScale, employeeTexture.getSize().y * npcScale);
    owner.setSize(ownerTexture.getSize().x * npcScale, ownerTexture.getSize().y * npcScale);
}

void LevelTwo::load()
{
    std::cout << "Level 2 loaded — Ally, Employee, Owner active\n";

    // Set positions
    ally.setPosX(200);
    ally.setPosY(400);
    // swap employee and owner positions: employee near the top, owner closer to diamond
    employee.setPosX(760);
    employee.setPosY(200);
    // place owner away from diamond (diamond is at ~600,400 in Game)
    owner.setPosX(500);
    owner.setPosY(400);

    // setup owner's detection zone centered on the owner
    owner.setupZone(120, 120);
    owner.setZoneCenter(owner.getPosX(), owner.getPosY());
    allySprite.setPosition(200, 400);
    // employee moved to top area
    employeeSprite.setPosition(employee.getPosX(), employee.getPosY());
    ownerSprite.setPosition(owner.getPosX(), owner.getPosY());

    // revive entities (in case level is replayed)
    ally.setIsAlive(true);
    ally.setHealth(100);
    // give ally a skill so its heal and buff scale
    ally.setSkill(2);
    employee.setIsAlive(true);
    employee.setHealth(100);
    // reset employee suspicion timer/counter
    employee.resetSuspicion();
    owner.setIsAlive(true);
    owner.setHealth(100);
}

void LevelTwo::update(float deltaTime, PlayerThief &player)
{
    // Ally heals player when touched (only if alive)
    if (ally.getIsAlive())
    {
        sf::FloatRect allyRect = allySprite.getGlobalBounds();
        if (allyRect.intersects(player.getBounds()))
            ally.healPlayer(player);
        // tick down any heal cooldown
        ally.updateCooldown(deltaTime);
    }

    // Employee increases suspicion
    employee.update(deltaTime, player);

    // Owner detection radius (use player's bounds)
    sf::FloatRect playerRect = player.getBounds();
    if (owner.getIsAlive() && owner.detectsPlayer(playerRect))
    {
        std::cout << "Owner caught you! Scene change triggered.\n";
        // Penalize player (set health to 0 so Game will return to MAIN_MENU)
        player.setHealth(0);
    }

    // Sync sprites with entity positions
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
    // draw owner's detection zone as translucent red rectangle (only when alive)
    if (owner.getIsAlive())
        window.draw(owner.getZone());
}
