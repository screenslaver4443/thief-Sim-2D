#ifndef UITHIRDLAYER_H
#define UITHIRDLAYER_H

#include "SecondLevel.h"
#include <string>

class Employee: Person {
    protected:
        int ID;
    public:
        int getID();
};

class Criminal: Person {
    protected:
        int skill;
        int strength;
    public:
        int getStrength();
        void setStrength(int);
        int getSkill();
        void setSkill(int);
};

class Loot: Item {
    private:
        double weight;
        double value;
    public:
        double getWeight();
        void setWeight(double);
        double getValue();
        void setValue(double);
};

class Text: UI {
    private:
        std::string contents;
        //font font;
        int fontSize;
        bool bold;
    public:
};

class Button: UI {
    private:
        bool enabled;
        std::string contents;
    public:
        void clicked();
};

class HealthIndicator: UI {
    private:
        int health;
    public:
        void setHealth(int);
        int getHealth();
};

#endif