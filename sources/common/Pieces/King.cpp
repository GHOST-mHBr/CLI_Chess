#include "King.hpp"
#include "../exceptions/BadCoord.hpp"

King::King(const PieceColor &color, const Coordinates &coord) : Piece(color, coord) {}

vector<Coordinates> King::getMoves(const Board &board) const
{
    vector<Coordinates> result;
    for (int8_t i = -1; i <= 1; i++)
    {
        for (int8_t j = -1; j <= 1; j++)
        {
            if (i == 0 && i == j) [[unlikely]]
            {
                continue;
            }
            Coordinates newCoord{static_cast<uint8_t>(i+coord.getX()), static_cast<uint8_t>(j+coord.getY())};
            if(!board.isCoordinatesInBoard(newCoord)){
                continue;
            }
            auto newPiece = board.getPieceAt(newCoord);
            if (newPiece == nullptr || (newPiece->getPieceColor() != pieceColor))
            {
                result.push_back(newCoord);
            }
        }
    }
    return result;
}

string King::getCharacter() const
{
    return pieceColor == PieceColor::BLACK ? "♔" : "♚";
}
