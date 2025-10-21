#include "Person.h"

Person::Person()
    : name("Unnamed"), age(0), isAlive(true), money(0.0f), health(100) {}

void Person::setHealth(int h)
{
    health = h;
    if (health < 0)
        health = 0;
    if (health > 100)
        health = 100;
}

int Person::getHealth() const { return health; }

void Person::setName(const std::string &n) { name = n; }
std::string Person::getName() const { return name; }

void Person::setAge(int a) { age = a; }
int Person::getAge() const { return age; }

void Person::setIsAlive(bool alive) { isAlive = alive; }
bool Person::getIsAlive() const { return isAlive; }
