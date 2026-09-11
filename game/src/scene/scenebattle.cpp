#include "scene.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "window.hpp"
#include "game.hpp"

SceneBattle::SceneBattle() {
    windowMenu = make_shared<WindowMenu>();
}

void SceneBattle::ready(Game& game) {
}

void SceneBattle::update(Game& game) {
}

void SceneBattle::render(Game& game) {
    Render::drawTexture(UI::ui["button_back"], Asset::texture["menu"]);

    if (game.menu == true) {
        windowMenu->render(game);
    }
}

void SceneBattle::mouseUpLeft(Game& game, Vector2 pos) {
    if (game.menu == false) {
        if (Util::pointInsideRectUI(pos, UI::ui["button_back"])) {
            game.menu = true;
        }
    } else {
        windowMenu->mouseUpLeft(game, pos);
    }
}
