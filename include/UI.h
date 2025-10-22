#ifndef UI_H
#define UI_H
// handles object collision and interactions

#include "Object.h"

class UI : Object
{
protected:
    bool gravity;
    bool collision;
    bool visible;

public:
    UI();
    UI(bool gravity, bool collision, bool visible);
    void setGravity(bool gravity);
    void setCollision(bool collision);
    void setVisible(bool visible);
};

#endif
