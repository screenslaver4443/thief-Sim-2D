#include "PlayerThief.h"
#include <fstream>
#include <sstream>
// player logic

PlayerThief::PlayerThief() : health(100) {}

void PlayerThief::takeDamage(int amount)
{
    health -= amount;
    if (health < 0)
        health = 0;
}

void PlayerThief::setHealth(int h)
{
    health = h;
    if (health < 0)
        health = 0;
    if (health > 100)
        health = 100;
}

int PlayerThief::getHealth() const
{
    return health;
}

sf::FloatRect PlayerThief::getBounds() const
{
    return sf::FloatRect(posX, posY, sizeX, sizeY);
}

bool PlayerThief::intersects(const Object &other) const
{
    sf::Vector2f otherPos = other.getPosition();
    sf::Vector2f otherSize = other.getSize();
    sf::FloatRect otherBounds(otherPos.x, otherPos.y, otherSize.x, otherSize.y);
    return getBounds().intersects(otherBounds);
}

void PlayerThief::setJustHealed(bool v) { justHealed = v; }

bool PlayerThief::getJustHealed() const { return justHealed; }

void PlayerThief::setSpeed(float s) { speed = s; }

float PlayerThief::getSpeed() const { return speed; }

void PlayerThief::applySpeedBuff(float multiplier, float durationSeconds)
{
    if (!speedBuffActive)
    {
        speed *= multiplier;
        speedBuffActive = true;
        speedBuffTimer = durationSeconds;
        speedBuffDuration = durationSeconds;
    }
}

void PlayerThief::updateBuff(float deltaTime)
{
    if (speedBuffActive)
    {
        speedBuffTimer -= deltaTime;
        if (speedBuffTimer <= 0.f)
        {
            speed = 200.0f;
            speedBuffActive = false;
            speedBuffTimer = 0.f;
        }
    }
}

bool PlayerThief::saveToFile(const std::string &path) const
{
    std::ofstream ofs(path);
    if (!ofs.is_open())
        return false;
    ofs << posX << " " << posY << " " << health << " " << speed << "\n";
    ofs.close();
    return true;
}

bool PlayerThief::loadFromFile(const std::string &path)
{
    std::ifstream ifs(path);
    if (!ifs.is_open())
        return false;
    float px, py;
    int h;
    float s;
    ifs >> px >> py >> h >> s;
    if (ifs.fail())
    {
        ifs.close();
        return false;
    }
    posX = px;
    posY = py;
    health = h;
    speed = s;
    ifs.close();
    return true;
}

std::string PlayerThief::toString() const
{
    std::ostringstream ss;
    ss << "Player(pos=" << posX << "," << posY << ", health=" << health << ", speed=" << speed << ")";
    return ss.str();
}
