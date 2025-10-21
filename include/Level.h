#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

#include "Object.h"

class Level {
 private:
  // ImageFilepath background;
  int width;
  int height;
  float gravity;

 public:
  std::vector<Object> contents;

 public:
  Level(int width, int height, float gravity, std::vector<Object> contents);
  ~Level();
  void addObject(Object object);
  float getGravity() { return this->gravity; }
};

#endif
