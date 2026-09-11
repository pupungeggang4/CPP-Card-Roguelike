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
    selectedMap = -1;
}

void SceneMap::update(Game& game) {
}

void SceneMap::render(Game& game) {
    Render::drawText(UI::ui["text_title"], "Select");
    Render::drawTexture(UI::ui["button_back"], Asset::texture["menu"]);

    for (int i = 0; i < 3; i++) {
        std::vector<float> pos = {
            UI::ui["button_map"][0] + UI::ui["button_map"][4] * i,
            UI::ui["button_map"][1]
        };
        Render::drawTexture(pos, Asset::texture["battle"]);

        if (selectedMap == i) {
            Render::drawTexture(pos, Asset::texture["selectframe240"]);
        }
    }

    Render::drawRect(UI::ui["button_map_select"], YELLOW);
    Render::drawText(UI::ui["text_map_select"], "Select");

    if (game.menu == true) {
        windowMenu->render(game);
    }
}

void SceneMap::mouseUpLeft(Game& game, Vector2 pos) {
    if (game.menu == false) {
        if (Util::pointInsideRectUI(pos, UI::ui["button_back"])) {
            game.menu = true;
        }

        for (int i = 0; i < 3; i++) {
            std::vector<float> rect = {
                UI::ui["button_map"][0] + UI::ui["button_map"][4] * i,
                UI::ui["button_map"][1],
                UI::ui["button_map"][2], UI::ui["button_map"][3]
            };

            if (Util::pointInsideRectUI(pos, rect)) {
                selectedMap = i;
            }
        }

        if (Util::pointInsideRectUI(pos, UI::ui["button_map_select"])) {
            if (selectedMap != -1) {
                game.changeSceneTo("battle");
            }
        }
    } else {
        windowMenu->mouseUpLeft(game, pos);
    }
}
