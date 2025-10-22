// self explanatory: press button to cause a scene change generally
#ifndef BUTTON_H
#define BUTTON_H

#include "UI.h"
#include <string>

class Button : UI
{
private:
    bool enabled;
    std::string contents;

public:
    Button(bool, std::string);
    void clicked();
};

#endif
