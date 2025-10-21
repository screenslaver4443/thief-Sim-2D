#ifndef STOREOWNER_H
#define STOREOWNER_H

#include "Employee.h"
#include <SFML/Graphics.hpp>

class StoreOwner : public Employee
{
private:
    sf::RectangleShape detectionZone;

public:
    StoreOwner(int x, int y);
    void setupZone(float width, float height);
    sf::RectangleShape getZone() const;
    bool detectsPlayer(sf::FloatRect playerBounds);
};

#endif
