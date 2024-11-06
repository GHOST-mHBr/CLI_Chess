#include "Knight.hpp"
#include "../exceptions/BadCoord.hpp"

Knight::Knight(const PieceColor &color, const Coordinates &coord) : Piece(color, coord) {}

vector<Coordinates> Knight::getMoves(const Board &board) const
{
    vector<Coordinates> result;
    int8_t validValues[] = {-2, -1, 1, 2};
    for (int8_t i : validValues)
    {
        for (int8_t j : validValues)
        {
            if(abs(i) + abs(j) != 3){
                continue;
            }
            
            Coordinates newCoord{(uint8_t)(i + coord.getX()), (uint8_t)(j + coord.getY())};
            if (!board.isCoordinatesInBoard(newCoord))
                continue;

            auto newPiece = board.getPieceAt(newCoord);
            if ((newPiece == nullptr) || (newPiece->getPieceColor() != pieceColor))
            {
                result.push_back(newCoord);
            }
        }
    }
    return result;
}

string Knight::getCharacter() const
{
    return pieceColor == PieceColor::BLACK ? "♘" : "♞";
}
