#include "entity/adventure.hpp"

Adventure::Adventure() {

}

void Adventure::initPlayer(int ID) {

}

void Adventure::initAdventure() {
    std::srand(std::time(NULL));
    std::array<std::string, 2> element = {"shop", "event"};
    layout = {};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            if (i % 2 == 0) {
                layout[i][j] = "battle";
            } else if (i != 9) {
                layout[i][j] = element[std::rand() % 2];
            } else {
                layout[i][j] = "boss";
            }
        }
    }
    floor = 0;
    gold = 50;
}
