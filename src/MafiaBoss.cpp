#include "MafiaBoss.h"
#include <iostream>
#include <cmath>

MafiaBoss::MafiaBoss() : active(false)
{
    this->setHealth(100);
}

void MafiaBoss::update(Security &security, PlayerThief &player, float deltaTime)
{
    if (!active || !this->getIsAlive())
        return;

    sf::Vector2f secPos = security.getPosition();
    sf::Vector2f myPos = getPosition();

    float dx = secPos.x - myPos.x;
    float dy = secPos.y - myPos.y;
    float dist = std::sqrt(dx * dx + dy * dy);

    // move towards security at speed 2.5 units per second
    if (dist > 1.0f)
    {
        float speed = 120.0f; // px/sec
        float nx = dx / dist;
        float ny = dy / dist;
        setPosX(myPos.x + nx * speed * deltaTime);
        setPosY(myPos.y + ny * speed * deltaTime);
    }

    // If player touches boss, boss takes out security and both are removed
    if (player.intersects(*this))
    {
        std::cout << "Boss touched! Boss and security removed from level\n";
        security.setIsAlive(false);
        security.setHealth(0);
        this->setIsAlive(false);
        this->setHealth(0);
    }
}
