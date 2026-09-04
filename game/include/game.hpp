#pragma once
#include "includes.hpp"

class Game {
    public:
        bool running = true;
        Game();
        void init();
        void loop();
        void render();
};
