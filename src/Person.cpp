#include "Person.h"
#include <iostream>
using namespace std;

#include "Person.h"

Person::Person()
{
    name = "Unnamed";
    age = 0;
    isAlive = true;
    money = 0.0f;
    health = 100;
}

Person::Person(std::string n, int a, bool alive, float m, int h)
{
    name = n;
    age = a;
    isAlive = alive;
    money = m;
    health = h;
}

std::string Person::getName() { return name; }
void Person::setName(std::string n) { name = n; }

int Person::getAge() { return age; }
void Person::setAge(int a) { age = a; }

bool Person::getIsAlive() { return isAlive; }
void Person::setIsAlive(bool alive) { isAlive = alive; }
