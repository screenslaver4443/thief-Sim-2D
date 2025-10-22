#ifndef LEVELONE_H
#define LEVELONE_H
// first level logic

#include "Level.h"

class LevelOne : public Level
{
public:
  LevelOne();
  void load() override;
  void update(float deltaTime, PlayerThief &player) override;
  void draw(sf::RenderWindow &window) override;
};

#endif
