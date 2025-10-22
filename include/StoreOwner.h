#ifndef STOREOWNER_H
#define STOREOWNER_H
// Store owner will blovk off an area as inaccessable, or else
// gameover

#include "Employee.h"
#include <SFML/Graphics.hpp>

class StoreOwner : public Employee
{
private:
    sf::RectangleShape detectionZone;

public:
    StoreOwner(int x = 0, int y = 0);
    void setupZone(float width, float height);
    void setZoneCenter(float centerX, float centerY);
    sf::RectangleShape getZone() const;
    bool detectsPlayer(sf::FloatRect playerBounds);
};

#endif
