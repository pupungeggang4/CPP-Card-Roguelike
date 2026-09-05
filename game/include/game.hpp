#pragma once
#include "includes.hpp"

class Scene;
class Game {
    public:
        bool running = true;
        Camera2D camera;

        Game();
        void init();
        void loop();
        void update();
        void handleInput();
        void render();
};
