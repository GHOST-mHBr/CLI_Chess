#include "Pawn.hpp"
#include "../exceptions/BadCoord.hpp"

Pawn::Pawn(const PieceColor &color, const Coordinates &coord) : Piece(color, coord) {}

vector<Coordinates> Pawn::getMoves(const Board &board) const
{
    vector<Coordinates> res;

    Coordinates newCoord;
    auto addIfEmptyToRes = [&res, &newCoord, &board]()
    {
        if (board.isCoordinatesInBoard(newCoord) && board.isEmpty(newCoord))
            res.push_back(newCoord);
    };

    auto addIfEnemyToRes = [&res, &newCoord, &board, this]()
    {
        if (!board.isCoordinatesInBoard(newCoord)){
            return;
        }
        auto newPiece = board.getPieceAt(newCoord);
        if (!board.isEmpty(newCoord) && pieceColor != newPiece->getPieceColor())
            res.push_back(newCoord);
    };

    if (pieceColor == PieceColor::WHITE)
    {
        if (coord.getY() == 1)
        { // Counting from zero
            newCoord = {coord.getX(), 2};
            addIfEmptyToRes();

            newCoord = {coord.getX(), 3};
            if (board.isEmpty({coord.getX(), 2}))
                addIfEmptyToRes();
        }
        else
        {
            newCoord = {coord.getX(), static_cast<uint8_t>(coord.getY() + 1)};
            addIfEmptyToRes();
        }
        newCoord = {static_cast<uint8_t>(coord.getX() - 1), static_cast<uint8_t>(coord.getY() + 1)};
        addIfEnemyToRes();
        newCoord = {static_cast<uint8_t>(coord.getX() + 1), static_cast<uint8_t>(coord.getY() + 1)};
        addIfEnemyToRes();
    }
    if (pieceColor == PieceColor::BLACK)
    {
        if (coord.getY() == board.getBoardSize() - 2)
        { // Counting from zero
            newCoord = {coord.getX(), static_cast<uint8_t>(board.getBoardSize() - 3)};
            addIfEmptyToRes();

            newCoord = {coord.getX(), static_cast<uint8_t>(board.getBoardSize() - 4)};
            if (board.isEmpty({coord.getX(), static_cast<uint8_t>(board.getBoardSize() - 3)}))
                addIfEmptyToRes();
        }
        else
        {
            newCoord = {coord.getX(), static_cast<uint8_t>(coord.getY() - 1)};
            addIfEmptyToRes();
        }
        newCoord = {static_cast<uint8_t>(coord.getX() - 1), static_cast<uint8_t>(coord.getY() - 1)};
        addIfEnemyToRes();
        newCoord = {static_cast<uint8_t>(coord.getX() + 1), static_cast<uint8_t>(coord.getY() - 1)};
        addIfEnemyToRes();
    }

    return res;
}

