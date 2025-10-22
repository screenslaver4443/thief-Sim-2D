#ifndef LEVEL_TWO_H
#define LEVEL_TWO_H
// second level logic

#include "Level.h"
#include "AllyThief.h"
#include "Employee.h"
#include "StoreOwner.h"
#include "PlayerThief.h"
#include <SFML/Graphics.hpp>

class LevelTwo : public Level
{
private:
    AllyThief ally;
    Employee employee;
    StoreOwner owner;

    sf::Texture allyTexture, employeeTexture, ownerTexture;
    sf::Sprite allySprite, employeeSprite, ownerSprite;

public:
    LevelTwo();
    void load() override;
    void update(float deltaTime, PlayerThief &player);
    void draw(sf::RenderWindow &window);
    bool hasEmployee() const override { return true; }
};

#endif
