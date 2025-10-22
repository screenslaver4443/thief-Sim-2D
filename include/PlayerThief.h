#ifndef PLAYERTHIEF_H
#define PLAYERTHIEF_H

#include "Object.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Savable.h"

class PlayerThief : public Object, public Savable
{
private:
    int health;
    bool justHealed = false;
    float speed = 200.0f; // default player movement speed (px/sec)
    // temporary speed buff
    bool speedBuffActive = false;
    float speedBuffTimer = 0.f;     // seconds remaining
    float speedBuffDuration = 5.0f; // default buff lasts 5s

public:
    PlayerThief();
    void takeDamage(int amount);
    void setHealth(int h);
    int getHealth() const;

    sf::FloatRect getBounds() const;
    bool intersects(const Object &other) const;
    void setJustHealed(bool v);
    bool getJustHealed() const;
    void setSpeed(float s);
    float getSpeed() const;
    // buff handling
    void applySpeedBuff(float multiplier, float durationSeconds);
    void updateBuff(float deltaTime);

    // persistence
    bool saveToFile(const std::string &path) const override;
    bool loadFromFile(const std::string &path) override;

    // debug
    std::string toString() const;
    std::string getSaveId() const override { return "player"; }
};

#endif
