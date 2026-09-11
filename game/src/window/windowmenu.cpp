#include "window.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "util.hpp"
#include "game.hpp"

WindowMenu::WindowMenu() {
}

void WindowMenu::ready(Game& game) {
}

void WindowMenu::update(Game& game) {
}

void WindowMenu::render(Game& game) {
    Render::drawRect(UI::ui["rect_menu"], YELLOW);
    Render::drawText(UI::ui["text_menu_pause"], "Paused");
    Render::drawRect(UI::ui["button_menu_resume"], PURPLE);
    Render::drawText(UI::ui["text_menu_resume"], "Resume");
    Render::drawRect(UI::ui["button_menu_exit"], ORANGE);
    Render::drawText(UI::ui["text_menu_exit"], "Exit to Title");
    Render::drawRect(UI::ui["button_menu_quit"], PURPLE);
    Render::drawText(UI::ui["text_menu_quit"], "Quit Game");
}

void WindowMenu::mouseUpLeft(Game& game, Vector2 pos) {
    if (Util::pointInsideRectUI(pos, UI::ui["button_menu_resume"])) {
        game.menu = false;
    } else if (Util::pointInsideRectUI(pos, UI::ui["button_menu_exit"])) {
        game.menu = false;
        game.changeSceneTo("title");
    } else if (Util::pointInsideRectUI(pos, UI::ui["button_menu_quit"])) {
        game.running = false;
    }
}
