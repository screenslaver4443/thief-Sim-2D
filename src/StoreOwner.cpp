#include "StoreOwner.h"

StoreOwner::StoreOwner(int x, int y)
{
    setPosition(x, y);
    this->setHealth(100);
    setupZone(150, 150);
}

void StoreOwner::setupZone(float width, float height)
{
    detectionZone.setSize(sf::Vector2f(width, height));
    detectionZone.setPosition(posX - width / 2, posY - height / 2);
    detectionZone.setFillColor(sf::Color(255, 0, 0, 80));
}

sf::RectangleShape StoreOwner::getZone() const
{
    return detectionZone;
}

bool StoreOwner::detectsPlayer(sf::FloatRect playerBounds)
{
    return detectionZone.getGlobalBounds().intersects(playerBounds);
}
