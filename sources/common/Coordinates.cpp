#include "Coordinates.hpp"
#include "exceptions/BadCoord.hpp"


Coordinates::Coordinates(pair<uint8_t, uint8_t> value):value(value){}

Coordinates::Coordinates(uint8_t x, uint8_t y){
    value.first=x;
    value.second=y;
}

Coordinates::Coordinates(const string& str){
    if(str.length() != 2){
        throw BadCoord{};
    }

    if(str[0] > 'z' || str[0] < 'a' || str[1] > '9' || str[1] < '0'){
        throw BadCoord{};
    }
    value.first = str[0]-'a';
    value.second = str[1]-'0';

}
