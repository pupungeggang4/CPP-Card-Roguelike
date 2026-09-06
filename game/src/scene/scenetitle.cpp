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
    DrawTextEx(Asset::font, "Card Roguelike", (Vector2){UI::ui["text_title"][0], UI::ui["text_title"][1]}, 32.0f, 0.0f, BLACK);
    DrawRectangle(UI::ui["button_start"][0], UI::ui["button_start"][1], UI::ui["button_start"][2], UI::ui["button_start"][3], MAGENTA); 
    DrawTextEx(Asset::font, "Start Game", (Vector2){UI::ui["text_start"][0], UI::ui["text_start"][1]}, 32.0f, 0.0f, BLACK); 
    DrawRectangle(UI::ui["button_quit"][0], UI::ui["button_quit"][1], UI::ui["button_quit"][2], UI::ui["button_quit"][3], YELLOW);
    DrawTextEx(Asset::font, "Quit Game", (Vector2){UI::ui["text_quit"][0], UI::ui["text_quit"][1]}, 32.0f, 0.0f, BLACK);
}

void SceneTitle::mouseUpLeft(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::ui["button_start"])) {
        game.changeSceneTo("ready");
    }
}
