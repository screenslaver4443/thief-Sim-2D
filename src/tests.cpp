#include <chrono>
#include <iostream>
#include <thread>

#include "Game.h"

int main() {
  Game::init();
  auto lastFrameTime = std::chrono::steady_clock::now();
  while (true) {
    auto currentFrameTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltaTimeRaw =
        currentFrameTime - lastFrameTime;
    float deltaTime = deltaTimeRaw.count();
    lastFrameTime = currentFrameTime;
    std::cout << "Delta Time: " << deltaTime << std::endl;
    Game::update(deltaTime);
  }
}