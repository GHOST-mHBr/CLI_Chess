#pragma once
#include "PieceColor.hpp"
#include "../Coordinates.hpp"
#include "../Board.hpp"
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

class Piece{
    friend Board;
    protected:
        const PieceColor pieceColor;
        Coordinates coord;

        Piece(const PieceColor color, const Coordinates& coord);

    private:
        void moveTo(const Coordinates& newCoord){
            coord=newCoord;
        }

    public:
        [[nodiscard]]const PieceColor getPieceColor()const noexcept{return pieceColor;}
        [[nodiscard]]const Coordinates& getCoordinates()const noexcept{return coord;}
        [[nodiscard]]virtual string getCharacter()const=0;
        [[nodiscard]]virtual vector<Coordinates> getMoves(const Board& board)const = 0;
        [[nodiscard]]virtual shared_ptr<Piece> clone()const = 0;
};
