#pragma once

#include <cstdint>
#include <string>
#include <utility>
#include <cassert>

using std::pair;
using std::string;


class Coordinates{

    private:
        pair<uint8_t,uint8_t> value; //x,y

    public:
        Coordinates(){value={0,0};};
        Coordinates(uint8_t, uint8_t);
        Coordinates(pair<uint8_t,uint8_t>);
        Coordinates(const string& str);


        [[nodiscard]] bool operator==(const Coordinates &other) const{
            return value == other.value;
        }

        [[nodiscard]] Coordinates operator+(const Coordinates& other){
            Coordinates res{pair<uint8_t,uint8_t>(getX()+other.getX(), getY()+other.getY())};
            return res;
        }

        [[nodiscard]] Coordinates operator+(Coordinates& other){
            Coordinates res{pair<uint8_t,uint8_t>(getX()+other.getX(), getY()+other.getY())};
            return res;
        }

        [[nodiscard]] uint8_t getX() const{
            return value.first;
        }

        [[nodiscard]] uint8_t getY() const{
            return value.second;
        }
        [[nodiscard]] string toString() const{
            string res = "("+ std::to_string(value.first) + "," + std::to_string(value.second) + ")";
            return res;
        }
};
