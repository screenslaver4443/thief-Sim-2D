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
    Person();
    Person(std::string n, int a, bool alive, float m, int h);

    std::string getName();
    void setName(std::string);
    int getAge();
    void setAge(int);
    bool getIsAlive();
    void setIsAlive(bool);
};

#endif
