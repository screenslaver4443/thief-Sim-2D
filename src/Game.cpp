//
// Created by Nikolai Pesudovs on 14/10/2025.
//
#include "Game.h"

#include "Level.h"

// Define static member variables
std::map<std::string, Level*> Game::scenes;
Level* Game::current_scene = nullptr;

void Game::initialize(std::map<std::string, Level*> scenes_map) {
  scenes = scenes_map;
  current_scene = nullptr;
}

void Game::cleanup() {
  for (auto& pair : scenes) {
    delete pair.second;
  }
  scenes.clear();
  current_scene = nullptr;
}

void Game::init() {
  scenes.insert(
      {"test", new Level(500, 500, 9.8f,
                         std::vector<Object>{Object(true, 0, 0, 10, 10)})});
  current_scene = scenes["test"];
  // more here
}

void Game::update(float deltaTime) {
  for (auto i : current_scene->contents) {
    i.handleGravity(current_scene->getGravity());
  }
}

void Game::render(float deltaTime) {}

void Game::close() {
  // Implementation to be added
}

void Game::change_current_scene(Level* scene) { current_scene = scene; }