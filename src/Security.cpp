#include "Security.h"
#include <iostream>
#include <cmath>
#include "Person.h"
// Security will walk to player at half player speed, and
// cause gameover if touched

Security::Security()
{
    this->setHealth(100);
}

void Security::chase(PlayerThief &player, float deltaTime)
{
    sf::Vector2f playerPos = player.getPosition();
    sf::Vector2f myPos = getPosition();

    float dx = playerPos.x - myPos.x;
    float dy = playerPos.y - myPos.y;
    float dist = std::sqrt(dx * dx + dy * dy);

    // chase only when within a range, so that player isny rushed
    if (dist < 300)
    {
        if (!isChasing)
        {
            std::cout << "Security chasing player!\n";
            isChasing = true;
        }
        float speed = 100.0f;
        if (dist > 1.0f)
        {
            float nx = dx / dist;
            float ny = dy / dist;
            setPosX(myPos.x + nx * speed * deltaTime);
            setPosY(myPos.y + ny * speed * deltaTime);
        }

        if (player.intersects(*this))
        {
            std::cout << "Player caught! Game Over!\n";
            player.setHealth(0);
        }
    }
    else
    {
        if (isChasing)
        {
            isChasing = false;
        }
    }
}
