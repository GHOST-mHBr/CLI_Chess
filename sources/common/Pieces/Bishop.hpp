#pragma once
#include "Piece.hpp"
#include <iostream>

using std::cout;
using std::endl;

class Bishop: public Piece{
    public:
        Bishop(const PieceColor& color, const Coordinates& coord);
        // Bishop(PieceColor& color, const Coordinates& coord);
        [[nodiscard]]vector<Coordinates> getMoves(const Board& board)const override;
        [[nodiscard]]string getCharacter()const override;
        [[nodiscard]]virtual shared_ptr<Piece> clone()const override{
            shared_ptr<Piece> result{ new Bishop(pieceColor, coord)};
            return result;
        }
};
