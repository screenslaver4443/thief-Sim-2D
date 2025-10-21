#ifndef LOOT_H
#define LOOT_H

#include "Item.h"

class Loot: Item {
    private:
        double weight;
        double value;
    public:
        double getWeight();
        void setWeight(double weight);
        double getValue();
        void setValue(double value);
};

#endif
