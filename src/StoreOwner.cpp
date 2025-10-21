#include "StoreOwner.h"

StoreOwner::StoreOwner(int suspicion, int level)
{
    this->suspicion = suspicion;
    this->level = level;
}

int StoreOwner::getSuspicion()
{
    return suspicion;
}

void StoreOwner::setSuspicion(int suspicion)
{
    this->suspicion = suspicion;
}

int StoreOwner::getLevel()
{
    return level;
}

void StoreOwner::setLevel(int level)
{
    this->level = level;
}