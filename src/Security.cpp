#include "Security.h"
#include <iostream>
#include <cmath>
#include "Person.h"

Security::Security()
{
    this->setHealth(100);
}

void Security::chase(PlayerThief &player)
{
    sf::Vector2f playerPos = player.getPosition();
    sf::Vector2f myPos = getPosition();

    float dx = playerPos.x - myPos.x;
    float dy = playerPos.y - myPos.y;
    float dist = std::sqrt(dx * dx + dy * dy);

    if (dist < 150)
    {
        std::cout << "Security chasing player!\n";
        if (player.intersects(*this))
        {
            std::cout << "Player caught! Game Over!\n";
            player.setHealth(0);
            // TODO: trigger scene change here
        }
    }
}
