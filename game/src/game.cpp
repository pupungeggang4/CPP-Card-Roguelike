#include "game.hpp"
#include "asset.hpp"
#include "scene.hpp"

Game::Game() {
}

void Game::init() {
    #ifdef __EMSCRIPTEN__
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
    Asset::loadAsset();

    scenes = std::unordered_map<std::string, shared_ptr<Scene>>();
    scenes["title"] = make_shared<SceneTitle>();
    scenes["ready"] = make_shared<SceneReady>();
    scene = scenes["title"];
    scene->ready(*this);
}

void Game::loop() {
    handleInput();
    scene->update(*this);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode2D(camera);
    scene->render(*this);
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

void Game::handleInput() {
    camera.zoom = GetRenderWidth() / 800.0f;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        #ifdef __EMSCRIPTEN__
        Vector2 pos = GetMousePosition();
        #else
        Vector2 pos = GetScreenToWorld2D(Vector2Scale(GetMousePosition(), GetWindowScaleDPI().x), camera);
        #endif
        std::cout << pos.x << ' ' << pos.y << std::endl;
        scene->mouseUpLeft(*this, pos);
    }
}

void Game::changeSceneTo(std::string target) {
    try {
        scene = scenes[target];
        scene->ready(*this);
    } catch (int e) {
        running = false;
    }
}
