// Ally will heal the player, essentially extending how much time they can
// spend in the level
#ifndef ALLYTHIEF_H
#define ALLYTHIEF_H

#include "Person.h"
#include "PlayerThief.h"

class AllyThief : public Person
{
private:
  float cooldown;
  int skill;

public:
  AllyThief();
  void setSkill(int s) { skill = s; }
  int getSkill() const { return skill; }
  void healPlayer(PlayerThief &player);
  void updateCooldown(float deltaTime);
  void resetCooldown();
  bool canHeal() const;
};

#endif
