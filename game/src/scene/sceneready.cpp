#include "scene.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "game.hpp"

SceneReady::SceneReady() {
}

void SceneReady::ready(Game& game) {
}

void SceneReady::update(Game& game) {
}

void SceneReady::render(Game& game) {
    DrawTextEx(Asset::font, "Select Character", (Vector2){UI::ui["text_title"][0], UI::ui["text_title"][1]}, 32.0f, 0.0f, BLACK);
    Render::drawRect(UI::ui["button_back"], BLUE);
}

void SceneReady::mouseUpLeft(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::ui["button_back"])) {
        game.changeSceneTo("title");
    }
}
