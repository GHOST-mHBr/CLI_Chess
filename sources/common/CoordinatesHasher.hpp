#pragma once
#include "Coordinates.hpp"
#include <cstddef>

class CoordinatesHasher{
    public:
    size_t operator()(const Coordinates& coord)const {
        return coord.getX()*8+coord.getY();
    }

    size_t operator()(const Coordinates& coord) {
        return operator()(coord);
    }
};
