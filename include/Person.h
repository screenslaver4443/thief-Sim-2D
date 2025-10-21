#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include <string>

class Person: virtual public Object{
    protected:
        std::string name;
        int age;
        bool isAlive;
        float money;
        int health;
    public:
        Person();
        Person(std::string name, int age, bool isAlive, float money, int health);
        std::string getName();
        void setName(std::string name);
        int getAge();
        void setAge(int age);
        bool getIsAlive();
        void setIsAlive(bool isAlive);
};

#endif
