#pragma once
#include "includes.hpp"

class Card;
class Item;
class Equipment;

class Adventure {
    public:
        int gold;
        int maxLife;

        int floor;
        
        std::vector<shared_ptr<Card>> deckOriginal;
        std::vector<shared_ptr<Item>> item;
        std::vector<shared_ptr<Equipment>> equipment;
        std::array<std::array<std::string, 3>, 10> layout;

        Adventure();
        void initPlayer(int);
        void initAdventure();
};
