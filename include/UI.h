#ifndef UI_H
#define UI_H

#include "Level.h"

class UI: Level {
    protected:
        bool gravity;
        bool collision;
        bool visible;
    public:
        void setGravity(bool);
        void setCollision(bool);
        void setVisible(bool);
};

#endif
