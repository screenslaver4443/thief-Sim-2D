#ifndef OBJECT_H
#define OBJECT_H
#include <string>

class Object {
 protected:
  std::string sprite;
  bool hasGravity;
  float posX;
  float posY;
  float sizeX;
  float sizeY;

 public:
  Object();
  Object(bool gravity, float X, float Y, float sizeX, float sizeY);
  void setPosX(float newX);
  void setPosY(float newY);
  void moveX(float X);
  void moveY(float Y);
  float getX();
  float getY();
  void handleGravity(float gravity);
};

#endif
