#ifndef OBJECT_H
#define OBJECT_H

class Object
{
protected:
    // ImageFilepath sprite;
    bool hasGravity;
    float posX;
    float posY;
    float sizeX;
    float sizeY;

public:
    Object(bool, float, float, float, float);
    void setPosX(float);
    void setPosY(float);
    float getPosX();
    float getPosY();
    float getSizeX();
    float getSizeY();

    Object()
    {
        hasGravity = false;
        posX = posY = 0;
        sizeX = sizeY = 0;
    }
};

#endif
