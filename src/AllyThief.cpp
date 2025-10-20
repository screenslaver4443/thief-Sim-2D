#include "AllyThief.h"
#include <iostream>
using namespace std;

AllyThief::AllyThief() {
    int bond=10;
}

void AllyThief::setBond(int bond) {
    this->bond=bond;
}

int AllyThief::getBond() {
    return bond;
}

int main() {
    AllyThief a1;
    cout << "The bond should be 10 and is set to " << a1.getBond() << endl;
}