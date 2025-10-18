//
// Created by Nikolai Pesudovs on 14/10/2025.
//

#ifndef GAME_H
#define GAME_H
#include <map>
#include <string>

#include "Level.h"
#include "Object.h"

class Game {
 private:
  static std::map<std::string, Level*> scenes;
  static Level* current_scene;

  // Private constructor to prevent instantiation
  Game() = delete;
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;

 public:
  static void initialize(std::map<std::string, Level*> scenes);
  static void cleanup();
  static void init();
  static void update(float deltaTime);
  static void render(float deltaTime);
  static void close();
  static void change_current_scene(Level* scene);
};

#endif  // GAME_H