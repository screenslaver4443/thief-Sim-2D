#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

#include "Object.h"

class Level
{
private:
    int width;
  int height;
  float gravity;
  std::vector<Object> elements;

public:
  Level(int width, int height, float gravity, std::vector<Object> contents);

  void setWidth(int w);
  void setHeight(int h);
  int getWidth() const;
  int getHeight() const;
};

#endif
