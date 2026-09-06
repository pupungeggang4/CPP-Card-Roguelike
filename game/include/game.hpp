#pragma once
#include "includes.hpp"

class Scene;
class Game {
    public:
        bool running = true;
        Camera2D camera;
        std::unordered_map<std::string, shared_ptr<Scene>> scenes;
        shared_ptr<Scene> scene;

        Game();
        void init();
        void loop();
        void handleInput();
        void changeSceneTo(std::string);
};
