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
    DrawTextEx(Asset::neodgm, "Select Character", (Vector2){UI::ui["text_title"][0], UI::ui["text_title"][1]}, 32.0f, 0.0f, BLACK);
    DrawTexture(Asset::texture["back"], UI::ui["button_back"][0], UI::ui["button_back"][1], WHITE);

    for (int i = 0; i < 6; i++) {
        int col = i % 3;
        int row = (i - col) / 3;
        std::vector<float> rect = {
            UI::ui["button_character"][0] + UI::ui["button_character"][4] * col,
            UI::ui["button_character"][1] + UI::ui["button_character"][5] * row,
            UI::ui["button_character"][2], UI::ui["button_character"][3]
        };
        if (i == selectedCharacter) {
            Render::drawRect(rect, BLUE);
        } else {
            Render::drawRect(rect, MAGENTA);
        }
    }
    Render::drawRect(UI::ui["button_game_start"], YELLOW);
    DrawTextEx(Asset::neodgm, "Start", (Vector2){UI::ui["text_game_start"][0], UI::ui["text_game_start"][1]}, 32.0f, 0.0f, BLACK);
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
