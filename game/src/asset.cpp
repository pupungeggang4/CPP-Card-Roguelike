#include "asset.hpp"

Font Asset::neodgm;
std::unordered_map<std::string, Texture2D> Asset::texture;

void Asset::loadAsset() {
    neodgm = LoadFont("asset/font/neodgm.ttf");
    texture.emplace("back", LoadTexture("asset/image/back.png"));
}

void Asset::dispose() {
    UnloadFont(neodgm);
    for (auto& pair : texture) {
        UnloadTexture(pair.second);
    }
}
