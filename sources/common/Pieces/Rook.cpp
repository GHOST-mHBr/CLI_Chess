#include "Rook.hpp"
#include "../exceptions/BadCoord.hpp"

Rook::Rook(const PieceColor &color, const Coordinates &coord) : Piece(color, coord) {}

vector<Coordinates> Rook::getMoves(const Board &board) const
{
    return board.getDirectMoves(coord, pieceColor);
}

string Rook::getCharacter() const
{
    return pieceColor == PieceColor::BLACK ? "♖" : "♜";
}
