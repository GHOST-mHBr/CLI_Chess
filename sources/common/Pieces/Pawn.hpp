#pragma once

#include "Piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(const PieceColor &color, const Coordinates &coord);

    [[nodiscard]] string getCharacter() const override
    {
        return pieceColor == PieceColor::WHITE ? "♟" : "♙";
    };

    [[nodiscard]] vector<Coordinates> getMoves(const Board &board) const override;
    
    [[nodiscard]] virtual shared_ptr<Piece> clone() const override
    {
        shared_ptr<Piece> result{new Pawn(pieceColor, coord)};
        return result;
    }
};
