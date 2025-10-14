#ifndef SECONDLEVEL_CLASS
#define SECONDLEVEL_CLASS

#include "BaseClass.h"
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
        Person(std::string, int, bool, float, int);
        std::string getName();
        void setName(std::string);
        int getAge();
        void setAge(int);
        bool getIsAlive();
        void setIsAlive(bool);
};

class Item: virtual public Object, virtual public Level {
    protected:
        std::string type;
        double value;
    public:
        std::string getType();
        void setType(std::string);
        double getValue();
        void setValue(double);
};

class UI: Level {
    protected:
        bool gravity;
        bool collision;
        bool visible;
    public:
        void setGravity(bool);
        void setCollision(bool);
        void setVisible(bool);
};

#endif