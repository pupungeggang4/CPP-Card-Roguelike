#pragma once
#include "includes.hpp"

class Game;
class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void mouseUpLeft(Game&, Vector2);
};

class SceneTitle : public Scene {
    public:
        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUpLeft(Game&, Vector2) override;
};

class SceneReady : public Scene {
    public:
        SceneReady();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUpLeft(Game&, Vector2) override;
};

class SceneCollection : public Scene {
};

class SceneGame : public Scene {
};
