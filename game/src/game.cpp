#include "game.hpp"

Game::Game() {
}

void Game::init() {
    InitWindow(800, 600, "Temp");
}

void Game::loop() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Temp", 320, 200, 20, DARKGRAY);
    EndDrawing();
}
