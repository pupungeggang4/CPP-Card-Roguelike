#pragma once
#include "includes.hpp"

class Asset {
    public:
        static Font neodgm;
        static std::unordered_map<std::string, Texture2D> texture;
        static void loadAsset();
        static void dispose();
};
