#ifndef HEALTHINDICATOR_H
#define HEALTHINDICATOR_H

#include "UI.h"

class HealthIndicator : UI {
 private:
  int health;

 public:
  void setHealth(int);
  int getHealth();
};

#endif
