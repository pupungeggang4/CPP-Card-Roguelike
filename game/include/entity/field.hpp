#pragma once

class Unit;

class Field {
    public:
        std::array<std::vector<shared_ptr<Unit>>, 2> unit;
        Field();
};
