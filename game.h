//
// Created by Nikolai Pesudovs on 14/10/2025.
//

#ifndef GAME_H
#define GAME_H
#include <vector>
#include "object.h"

class game {
    private:
        std::vector<scenes*> scenes;
    public:
        game(std::vector<scenes*> scenes) : scenes(scenes) {}
        virtual ~game() {}
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void shutdown() = 0;
};



#endif //GAME_H
