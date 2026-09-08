#include "ui.hpp"

std::unordered_map<std::string, std::vector<float>> UI::ui = {
    {"text_title", {20.0f, 20.0f}},
    {"button_start", {100.0f, 80.0f, 600.0f, 80.0f}},
    {"text_start", {120.0f, 100.0f}},
    {"button_quit", {100.0f, 160.0f, 600.0f, 80.0f}},
    {"text_quit", {120.0f, 180.0f}},
    {"button_back", {740.0f, 20.0f, 40.0f, 40.0f}},
    {"button_character", {20.0f, 80.0f, 120.0f, 120.0f, 140.0f, 140.0f}},
    {"button_game_start", {620.0f, 500.0f, 160.0f, 80.0f}},
    {"text_game_start", {640.0f, 520.0f}}
};
