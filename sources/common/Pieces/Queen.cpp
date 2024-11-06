#include "Queen.hpp"
#include "../exceptions/BadCoord.hpp"

Queen::Queen(const PieceColor &color, const Coordinates &coord) : Piece(color, coord) {}

vector<Coordinates> Queen::getMoves(const Board &board) const
{
    vector<Coordinates> result, temp;

    result = board.getDiagonalMoves(coord, pieceColor);
    temp = board.getDirectMoves(coord, pieceColor);
    result.insert(result.cend(), temp.cbegin(), temp.cend());
    return result;
}

string Queen::getCharacter() const
{
    return pieceColor == PieceColor::WHITE ? "♛" : "♕";
}
