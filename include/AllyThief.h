#ifndef ALLYTHIEF_H
#define ALLYTHIEF_H

#include "Person.h"
#include "PlayerThief.h"

class AllyThief : public Person
{
public:
  AllyThief();
  void healPlayer(PlayerThief &player);
};

#endif
