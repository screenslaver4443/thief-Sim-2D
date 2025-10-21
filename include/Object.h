#ifndef OBJECT_H
#define OBJECT_H

class Object {
    protected: 
        //ImageFilepath sprite;
        bool hasGravity;
        float posX;
        float posY;
        float sizeX;
        float sizeY;
    public:
        Object();
        Object(bool hasGravity, float posX, float poxY, float sizeX, float sizeY);
        void setPosX(float posX);
        void setPosY(float posY);
        float getSizeX();
        float getSizeY();
};

#endif
