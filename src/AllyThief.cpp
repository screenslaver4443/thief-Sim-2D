// the ally theif will heal the player

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
}

void AllyThief::healPlayer(PlayerThief &player)
{
    const int MAX_HEALTH = 100;
    if (player.intersects(*this))
    {
        player.setHealth(MAX_HEALTH);
        player.setJustHealed(true);
        std::cout << "Ally Thief healed the player to full health!\n";
    }
}
