#include "game.hpp"

Game::Game() {
}

void Game::init() {
    InitWindow(800, 600, "Temp");
}

void Game::loop() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    render();
    EndDrawing();

    #ifdef __EMSCRIPTEN__
    if (!running) {
        emscripten_cancel_main_loop();
    }
    #else
    if (WindowShouldClose()) {
        running = false;
    }
    #endif
}

void Game::render() {
    DrawText("Temp", 320, 200, 20, DARKGRAY);
}
