#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
    name="ABCDE";
    age=18;
    isAlive=true;
    money=0.00;
    health=100;
}

Person::Person(string name, int age, bool isAlive, float money, int health) {
    this->name=name;
    this->age=age;
    this->isAlive=isAlive;
    this->money=money;
    this->health=health;
}

string Person::getName() {
    return name;
}

void Person::setName(string name) {
    this->name=name;
}

int Person::getAge() {
    return age;
}

void Person::setAge(int age) {
    this->age=age;
}

bool Person::getIsAlive() {
    return isAlive;
}

void Person::setIsAlive(bool isAlive) {
    this->isAlive=isAlive;
}
    