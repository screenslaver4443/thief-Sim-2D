#include "AllyThief.h"
#include <iostream>
using namespace std;

AllyThief::AllyThief(int bond) {
    this->bond=bond;
}

void AllyThief::setBond(int bond) {
    this->bond=bond;
}

int AllyThief::getBond() {
    return bond;
}