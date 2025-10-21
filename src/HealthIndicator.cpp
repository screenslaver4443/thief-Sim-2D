#include "HealthIndicator.h"

HealthIndicator::HealthIndicator(int health) {
  health=100;
}

void HealthIndicator::setHealth(int health) {
    this->health=health;
}

int HealthIndicator::getHealth() {
    return health;
}