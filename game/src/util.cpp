#include "util.hpp"
#include "asset.hpp"

bool Util::pointInsideRectUI(Vector2 pos, std::vector<float> rect) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}

void Render::drawRect(std::vector<float> rect, Color color) {
    DrawRectangle(rect[0], rect[1], rect[2], rect[3], color);
}

void Render::drawText(std::vector<float> pos, const char* text, float size, Color color) {
    DrawTextEx(Asset::neodgm, text, (Vector2){pos[0], pos[1]}, size, 0.0f, color);
}

void Render::drawTexture(std::vector<float> pos, Texture2D texture) {
    DrawTexture(texture, pos[0], pos[1], WHITE); 
}
