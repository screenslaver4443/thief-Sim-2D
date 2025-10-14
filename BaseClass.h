#ifndef BASE_CLASS
#define BASE_CLASS

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
        Object(bool, float, float, float, float);
        void setPosX(float);
        void setPosY(float);
        float getSizeX();
        float getSizeY();
};

class Level {
    private:
        //ImageFilepath background;
        int width;
        int height;
    public:
        void setWidth(int);
        void setHeight(int);
};

#endif