#include "scene.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "game.hpp"

SceneTitle::SceneTitle() {
}

void SceneTitle::ready(Game& game) {
}

void SceneTitle::update(Game& game) {
}

void SceneTitle::render(Game& game) {
    Render::drawText(UI::ui["text_title"], "Card Roguelike");
    Render::drawRect(UI::ui["button_start"], MAGENTA);
    Render::drawText(UI::ui["text_start"], "Start Game");
    Render::drawRect(UI::ui["button_quit"], YELLOW);
    Render::drawText(UI::ui["text_quit"], "Quit Game");
}

void SceneTitle::mouseUpLeft(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::ui["button_start"])) {
        game.changeSceneTo("ready");
    } else if (Util::pointInsideRectUI(pos, UI::ui["button_quit"])) {
        game.running = false;
    }
}
