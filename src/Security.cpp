#include "Security.h"

Security::Security(int suspicion, int level)
{
    this->suspicion = suspicion;
    this->level = level;
}

int Security::getSuspicion()
{
    return suspicion;
}

void Security::setSuspicion(int suspicion)
{
    this->suspicion = suspicion;
}

int Security::getLevel()
{
    return level;
}

void Security::setLevel(int level)
{
    this->level = level;
}