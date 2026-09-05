#pragma once
#include "includes.hpp"

class Game {
    public:
        bool running = true;
        Camera2D camera;

        Game();
        void init();
        void loop();
        void render();
};
