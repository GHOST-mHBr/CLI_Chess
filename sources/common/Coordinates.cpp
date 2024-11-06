#include "Coordinates.hpp"
#include "exceptions/BadCoord.hpp"


Coordinates::Coordinates(pair<uint8_t, uint8_t> value):value(value){}

Coordinates::Coordinates(uint8_t x, uint8_t y){
    value.first=x;
    value.second=y;
}
