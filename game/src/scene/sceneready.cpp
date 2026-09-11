#include "scene.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "game.hpp"

SceneReady::SceneReady() {
}

void SceneReady::ready(Game& game) {
    selectedCharacter = -1;
}

void SceneReady::update(Game& game) {
}

void SceneReady::render(Game& game) {
    Render::drawText(UI::ui["text_title"], "Select Character");
    DrawTexture(Asset::texture["back"], UI::ui["button_back"][0], UI::ui["button_back"][1], WHITE);

    std::vector<std::string> texList = {"fire", "water", "wind", "earth", "light", "rainbow"};
    for (int i = 0; i < 6; i++) {
        int col = i % 3;
        int row = (i - col) / 3;
        std::vector<float> pos = {
            UI::ui["button_character"][0] + UI::ui["button_character"][4] * col,
            UI::ui["button_character"][1] + UI::ui["button_character"][5] * row,
        };
        if (Asset::texture.find(texList[i]) != Asset::texture.end()) {
            Render::drawTexture(pos, Asset::texture[texList[i]]);
        }
        if (selectedCharacter == i) {
            Render::drawTexture(pos, Asset::texture["selectframe"]);
        }
    }
    Render::drawRect(UI::ui["button_game_start"], YELLOW);
    Render::drawText(UI::ui["text_game_start"], "Start");
}

void SceneReady::mouseUpLeft(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::ui["button_back"])) {
        game.changeSceneTo("title");
    }

    for (int i = 0; i < 6; i++) {
        int col = i % 3;
        int row = (i - col) / 3;
        std::vector<float> rect = {
            UI::ui["button_character"][0] + UI::ui["button_character"][4] * col,
            UI::ui["button_character"][1] + UI::ui["button_character"][5] * row,
            UI::ui["button_character"][2], UI::ui["button_character"][3]
        };

        if (Util::pointInsideRectUI(pos, rect)) {
            selectedCharacter = i;
        }
    }

    if (Util::pointInsideRectUI(pos, UI::ui["button_game_start"])) {
        if (selectedCharacter != -1) {
            game.changeSceneTo("map");
        }
    }
}
