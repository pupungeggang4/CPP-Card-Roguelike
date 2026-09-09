#pragma once
#include "includes.hpp"

class Game;
class Window {
    public:
        Window();
        void ready(Game&);
        void update(Game&);
        void render(Game&);
        void mouseUpLeft(Game&);
};
