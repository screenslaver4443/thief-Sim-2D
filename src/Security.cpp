#include "Security.h"
#include <iostream>
#include <cmath>
#include "Person.h"

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

    // chase only when within a range
    if (dist < 300)
    {
        if (!isChasing)
        {
            std::cout << "Security chasing player!\n";
            isChasing = true;
        }
        // move at half player speed in px/sec; player speed ~200 so security ~100
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
            // actual scene change handled in Game::update
        }
    }
    else
    {
        if (isChasing)
        {
            // stopped chasing
            isChasing = false;
        }
    }
}
