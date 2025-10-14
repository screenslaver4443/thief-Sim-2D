//
// Created by Nikolai Pesudovs on 14/10/2025.
//

#ifndef GAME_H
#define GAME_H
#include <map>
#include <string>
#include "object.h"
#include "scene.h"

class game {
    private:
        std::map<std::string, scene*> scenes;
        scene *current_scene;


    public:
        game(std::map<std::string, scene*> scenes) : scenes(scenes) {}
        ~game() {}
        void init();
        void update(float deltaTime);
        void render(float deltaTime);
        void close();
        void change_current_scene(scene *scene);
};



#endif //GAME_H
