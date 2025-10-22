#include "HealthIndicator.h"
// passes the display for the health bar

HealthIndicator::HealthIndicator(int health)
{
  health = 100;
}

void HealthIndicator::setHealth(int health)
{
  this->health = health;
}

int HealthIndicator::getHealth()
{
  return health;
}