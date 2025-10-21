#include "Employee.h"

Employee::Employee() {
    ID=0000;
}

Employee::Employee(int ID) {
    this->ID=ID;
}

int Employee::getID() {
    return ID;
}