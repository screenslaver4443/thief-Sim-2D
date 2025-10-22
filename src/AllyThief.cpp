// Ally will heal the player, esdentially extending how much time they can
// spend in the level
#include "AllyThief.h"
#include "PlayerThief.h"
#include <iostream>
#include <cmath>
#include "Person.h"

AllyThief::AllyThief()
{
    setName("Ally Thief");
    setAge(25);
    setIsAlive(true);
    cooldown = 0.f;
    skill = 1;
}

void AllyThief::healPlayer(PlayerThief &player)
{
    const int MAX_HEALTH = 100;
    if (player.intersects(*this) && cooldown <= 0.f)
    {
        // heal based on skill (skill=1 -> full heal, higher -> still full but buff scales)
        int healAmount = 20 * skill; // additive heal amount
        int newHealth = player.getHealth() + healAmount;
        if (newHealth > MAX_HEALTH)
            newHealth = MAX_HEALTH;
        player.setHealth(newHealth);
        player.setJustHealed(true);
        // apply a small temporary speed buff based on ally skill
        float multiplier = 1.0f + 0.1f * static_cast<float>(skill); // e.g., skill=1 -> 1.1x
        float duration = 2.0f * static_cast<float>(skill);          // seconds
        player.applySpeedBuff(multiplier, duration);
        cooldown = 3.0f; // 3 second cooldown between heals
        std::cout << "Ally Thief healed the player by " << healAmount << " and applied speed buff x" << multiplier << " for " << duration << "s\n";
    }
}

void AllyThief::updateCooldown(float deltaTime)
{
    if (cooldown > 0.f)
        cooldown -= deltaTime;
}

void AllyThief::resetCooldown()
{
    cooldown = 0.f;
}

bool AllyThief::canHeal() const
{
    return cooldown <= 0.f;
}
