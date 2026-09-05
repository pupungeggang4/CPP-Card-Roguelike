#include "asset.hpp"

Font Asset::font;

void Asset::loadAsset() {
    font = LoadFont("asset/font/neodgm.ttf");
}
