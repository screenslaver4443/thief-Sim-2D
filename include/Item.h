#ifndef ITEM_H
#define ITEM_H

#include <string>

#include "Level.h"
#include "Object.h"

class Item : virtual public Object, virtual public Level {
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
