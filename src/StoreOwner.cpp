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
    // set the origin to the center to make positioning easier
    detectionZone.setOrigin(width / 2, height / 2);
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

void StoreOwner::setZoneCenter(float centerX, float centerY)
{
    detectionZone.setPosition(centerX, centerY);
}
