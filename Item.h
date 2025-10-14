#ifndef ITEM_H
#define ITEM_H

#include "Object.h"
#include "Level.h"
#include <string>

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

#endif
