#pragma once
#include "includes.hpp"

class Util {
    public:
        static bool pointInsideRectUI(Vector2, std::vector<float>);
};

class Render {
    public:
        static void drawRect(std::vector<float>, Color);
        static void drawText(std::vector<float>, const char*, float size = 32.0f, Color color = BLACK);
};
