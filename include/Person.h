#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include <string>

class Person : public Object
{
protected:
    std::string name;
    int age;
    bool isAlive;
    float money;
    int health;

public:
    Person();
    virtual ~Person() = default;

    void setHealth(int h);
    int getHealth() const;

    void setName(const std::string &n);
    std::string getName() const;

    void setAge(int a);
    int getAge() const;

    void setIsAlive(bool alive);
    bool getIsAlive() const;
};

#endif
