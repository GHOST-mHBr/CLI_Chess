#pragma once
#include "Piece.hpp"

class Rook: public Piece{
    public:
        Rook(const PieceColor& color, const Coordinates& coord);
        // Bishop(PieceColor& color, const Coordinates& coord);
        [[nodiscard]]vector<Coordinates> getMoves(const Board& board)const override;
        [[nodiscard]]string getCharacter()const override;
        [[nodiscard]]virtual shared_ptr<Piece> clone()const override{
            shared_ptr<Piece> result{ new Rook(pieceColor, coord)};
            return result;
        }
};
