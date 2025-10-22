#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H
// third level logic

#include "Level.h"
#include "Employee.h"
#include "Security.h"
#include "MafiaBoss.h"
#include "PlayerThief.h"
#include <SFML/Graphics.hpp>

class LevelThree : public Level
{
private:
    Employee employee;
    Security security;
    MafiaBoss boss;
    bool bossActivated;

    sf::Texture employeeTexture, securityTexture, bossTexture;
    sf::Sprite employeeSprite, securitySprite, bossSprite;

public:
    LevelThree();
    void load() override;
    void update(float deltaTime, PlayerThief &player);
    void draw(sf::RenderWindow &window);
    bool hasEmployee() const override { return true; }
};

#endif
