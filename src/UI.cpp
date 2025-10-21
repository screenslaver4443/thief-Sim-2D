#include "UI.h"

UI::UI() {
    gravity=true;
    collision=false;
    visible=true;
}

UI::UI(bool gravity, bool collision, bool visible) {
    this->gravity=gravity;
    this->collision=collision;
    this->visible=visible;
}

void UI::setGravity(bool gravity) {
    this->gravity=gravity;
}

void UI::setCollision(bool collision) {
    this->collision=collision;
}

void UI::setVisible(bool visible) {
    this->visible=visible;
}