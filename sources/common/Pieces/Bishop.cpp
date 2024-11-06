#include "Bishop.hpp"
#include "../exceptions/BadCoord.hpp"
#include "../exceptions/BadMove.hpp"
#include <cmath>

Bishop::Bishop(const PieceColor &color, const Coordinates &coord) : Piece(color, coord) {}

vector<Coordinates> Bishop::getMoves(const Board &board) const
{
    return board.getDiagonalMoves(coord, pieceColor);
}

string Bishop::getCharacter() const
{
    return pieceColor == PieceColor::BLACK ? "♗" : "♝";
}
