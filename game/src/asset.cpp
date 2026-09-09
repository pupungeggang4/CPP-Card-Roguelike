#include "asset.hpp"

Font Asset::neodgm;
std::unordered_map<std::string, Texture2D> Asset::texture;

void Asset::loadAsset() {
    int codepoints[18000] = {0};
    int count = 0;
    for (int i = 0; i < 95; i++) codepoints[count++] = 32 + i;
    for (int i = 0xAC00; i <= 0xD7A3; i++) codepoints[count++] = i;
    for (int i = 0x4E00; i <= 0x6400; i++) codepoints[count++] = i;
    for (int i = 0x3040; i <= 0x309F; i++) codepoints[count++] = i;
    for (int i = 0x30A0; i <= 0x30FF; i++) codepoints[count++] = i;
    neodgm = LoadFontEx("asset/font/neodgm.ttf", 16, codepoints, count);
    texture.emplace("back", LoadTexture("asset/image/back.png"));
}

void Asset::dispose() {
    UnloadFont(neodgm);
    for (auto& pair : texture) {
        UnloadTexture(pair.second);
    }
}
