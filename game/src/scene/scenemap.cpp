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
    Render::drawText(UI::ui["text_title"], "Select");
    DrawTexture(Asset::texture["back"], UI::ui["button_back"][0], UI::ui["button_back"][1], WHITE);

    if (game.menu == true) {
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
