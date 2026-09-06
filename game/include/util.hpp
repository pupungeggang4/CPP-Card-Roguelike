#pragma once
#include "includes.hpp"

class Util {
    public:
        static bool pointInsideRectUI(Vector2, std::vector<float>);
};

class Render {
    public:
        static void drawRect(std::vector<float>, Color);
};
