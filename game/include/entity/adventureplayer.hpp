#pragma once
#include "includes.hpp"

class Card;
class Item;
class Equipment;

class AdventurePlayer {
    public:
        int gold;
        int maxLife;
        std::vector<shared_ptr<Card>> deckOriginal;
        std::vector<shared_ptr<Item>> item;
        std::vector<shared_ptr<Equipment>> equipment;
        AdventurePlayer();

        void initPlayer(int);
};
