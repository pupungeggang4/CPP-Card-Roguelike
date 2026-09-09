#include "scene.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "window.hpp"
#include "game.hpp"

SceneMap::SceneMap() {
    windowMenu = make_shared<WindowMenu>();
}

void SceneMap::ready(Game& game) {
}

void SceneMap::update(Game& game) {
}

void SceneMap::render(Game& game) {
    DrawTextEx(Asset::neodgm, "Select", (Vector2){UI::ui["text_title"][0], UI::ui["text_title"][1]}, 32.0f, 0.0f, BLACK);
    DrawTexture(Asset::texture["back"], UI::ui["button_back"][0], UI::ui["button_back"][1], WHITE);

    if (game.menu == false) {
        windowMenu->render(game);
    }
}

void SceneMap::mouseUpLeft(Game& game, Vector2 pos) {
    if (game.menu == false) {
        if (Util::pointInsideRectUI(pos, UI::ui["button_back"])) {
            game.menu = true;
        }
    } else {
        windowMenu->mouseUpLeft(game, pos);
    }
}
