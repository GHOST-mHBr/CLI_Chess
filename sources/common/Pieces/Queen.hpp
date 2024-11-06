#pragma once
#include "Piece.hpp"

class Queen : public Piece{
    public:
        Queen(const PieceColor& color, const Coordinates& coord);

        [[nodiscard]]vector<Coordinates> getMoves(const Board& board)const override;
        [[nodiscard]]string getCharacter()const override;
        [[nodiscard]]virtual shared_ptr<Piece> clone()const override{
            shared_ptr<Piece> result{ new Queen(pieceColor, coord)};
            return result;
        }
};
