#include "game.hpp"

Game::Game() {
}

void Game::init() {
    #ifdef __EMSCRITPEN__
    InitWindow(800, 600, "Card Roguelike");
    #else
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Card Roguelike");
    SetExitKey(KEY_NULL);

    int width, height;
    int currentMonitor = GetCurrentMonitor();
    int monitorWidth = GetMonitorWidth(currentMonitor);
    int monitorHeight = GetMonitorHeight(currentMonitor);

    if (monitorWidth * 3 > monitorHeight * 4) {
        height = monitorHeight * 0.8f;
        width = height * 4 / 3;
    } else {
        width = monitorWidth * 0.8f;
        height = monitorHeight * 3 / 4;
    }

    SetWindowSize(width, height);
    SetWindowPosition(
        (monitorWidth - width) / 2, (monitorHeight - height) / 2
    );
    #endif

    camera.zoom = GetRenderWidth() / 800.0f;
}

void Game::loop() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(camera);
    render();
    EndMode2D();
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
    DrawText("Temp", 400, 300, 20, DARKGRAY);
}
