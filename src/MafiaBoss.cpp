#include "MafiaBoss.h"
#include <iostream>

MafiaBoss::MafiaBoss() : active(false)
{
    this->setHealth(100);
}

void MafiaBoss::update(Security &security)
{
    if (!active)
        return;

    sf::Vector2f secPos = security.getPosition();
    sf::Vector2f myPos = getPosition();

    if (std::abs(secPos.x - myPos.x) < 10 && std::abs(secPos.y - myPos.y) < 10)
    {
        std::cout << "Boss neutralized security!\n";
        this->setHealth(90);
    }
}
