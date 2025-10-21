#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include <string>

class Person : virtual public Object
{
protected:
    std::string name;
    int age;
    bool isAlive;
    float money;
    int health;

public:
    // you stinkies forgot the constructor
    Person()
        : name("Unnamed"), age(0), isAlive(true), money(0.0f), health(100) {}

    Person(std::string n, int a, bool alive, float m, int h)
        : name(n), age(a), isAlive(alive), money(m), health(h) {}
    std::string getName();
    void setName(std::string);
    int getAge();
    void setAge(int);
    bool getIsAlive();
    void setIsAlive(bool);
};

#endif
