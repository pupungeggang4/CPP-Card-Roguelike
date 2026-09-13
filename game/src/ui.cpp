#include "ui.hpp"

std::unordered_map<std::string, std::vector<float>> UI::ui = {
    {"text_title", {20.0f, 20.0f}},
    {"button_start", {100.0f, 80.0f, 600.0f, 80.0f}},
    {"text_start", {120.0f, 100.0f}},
    {"button_quit", {100.0f, 160.0f, 600.0f, 80.0f}},
    {"text_quit", {120.0f, 180.0f}},
    {"button_back", {740.0f, 20.0f, 40.0f, 40.0f}},
    {"button_character", {20.0f, 80.0f, 160.0f, 160.0f, 180.0f, 180.0f}},
    {"button_game_start", {620.0f, 500.0f, 160.0f, 80.0f}},
    {"text_game_start", {640.0f, 520.0f}},
    
    {"rect_menu", {160.0f, 140.0f, 480.0f, 240.0f}},
    {"text_menu_pause", {180.0f, 160.0f}},
    {"button_menu_resume", {160.0f, 220.0f, 480.0f, 80.0f}},
    {"text_menu_resume", {180.0f, 240.0f}},
    {"button_menu_exit", {160.0f, 300.0f, 480.0f, 80.0f}},
    {"text_menu_exit", {180.0f, 320.0f}},
    {"button_menu_quit", {160.0f, 380.0f, 480.0f, 80.0f}},
    {"text_menu_quit", {180.0f, 400.0f}},

    {"button_map", {20.0f, 180.0f, 240.0f, 240.0f, 260.0f, 0.0f}},
    {"text_map_floor", {20.0f, 60.0f}},
    {"text_map_gold", {20.0f, 100.0f}},
    {"button_map_select", {320.0f, 500.0f, 160.0f, 80.0f}},
    {"text_map_select", {340.0f, 520.0f}},
};
