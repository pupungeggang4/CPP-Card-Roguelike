#pragma once
#include "includes.hpp"

class Game;

class Window {
    public:
        Window();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void mouseUpLeft(Game&, Vector2);
};

class WindowMenu : public Window {
    public:
        WindowMenu();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUpLeft(Game&, Vector2) override;
};

class WindowReward : public Window {
    public:
        WindowReward();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUpLeft(Game&, Vector2) override;
};
