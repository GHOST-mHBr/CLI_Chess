#include "Board.hpp"
#include "Coordinates.hpp"
#include "Pieces/Pawn.hpp"
#include "Pieces/Bishop.hpp"
#include "Pieces/Rook.hpp"
#include "Pieces/Knight.hpp"
#include "Pieces/King.hpp"
#include "Pieces/Queen.hpp"
#include "exceptions/BadMove.hpp"
#include "exceptions/BadCoord.hpp"
#include "PrettyPrint.hpp"

Board::Board(uint8_t size) : boardSize(size)
{
    arrangePieces();
}

void Board::arrangePieces()
{
    //========= pawns ============
    for (uint8_t i = 0; i < boardSize; i++)
    {
        const Coordinates whiteCoord{i, 1};
        shared_ptr<Piece> whitePawn{new Pawn{PieceColor::WHITE, whiteCoord}};
        piecesMap.insert({whiteCoord, std::move(whitePawn)});

        const Coordinates blackCoord{i, static_cast<uint8_t>(boardSize - 2)};
        shared_ptr<Piece> blackPawn{new Pawn{PieceColor::BLACK, blackCoord}};
        piecesMap.insert({blackCoord, std::move(blackPawn)});
    }
    //========= end of pawns ========

    //========= rooks =========
    shared_ptr<Piece> whiteRook{new Rook{PieceColor::WHITE, rooksCoords[0]}};
    piecesMap.insert({rooksCoords[0], std::move(whiteRook)});
    whiteRook.reset(new Rook{PieceColor::WHITE, rooksCoords[1]});
    piecesMap.insert({rooksCoords[1], std::move(whiteRook)});

    shared_ptr<Piece> blackRook{new Rook{PieceColor::BLACK, rooksCoords[2]}};
    piecesMap.insert({rooksCoords[2], std::move(blackRook)});
    blackRook.reset(new Rook{PieceColor::BLACK, rooksCoords[3]});
    piecesMap.insert({rooksCoords[3], std::move(blackRook)});
    //====== end of rooks =======

    //========= knights =========
    shared_ptr<Piece> whiteKnight{new Knight{PieceColor::WHITE, knightsCoords[0]}};
    piecesMap.insert({knightsCoords[0], std::move(whiteKnight)});
    whiteKnight.reset(new Knight{PieceColor::WHITE, knightsCoords[1]});
    piecesMap.insert({knightsCoords[1], std::move(whiteKnight)});

    shared_ptr<Piece> blackKnight{new Knight{PieceColor::BLACK, knightsCoords[2]}};
    piecesMap.insert({knightsCoords[2], std::move(blackKnight)});
    blackKnight.reset(new Knight{PieceColor::BLACK, knightsCoords[3]});
    piecesMap.insert({knightsCoords[3], std::move(blackKnight)});
    //====== end of knights =======

    //========= bishops =========
    shared_ptr<Piece> whiteBishop{new Bishop{PieceColor::WHITE, bishopsCoords[0]}};
    piecesMap.insert({bishopsCoords[0], std::move(whiteBishop)});
    whiteBishop.reset(new Bishop{PieceColor::WHITE, bishopsCoords[1]});
    piecesMap.insert({bishopsCoords[1], std::move(whiteBishop)});

    shared_ptr<Piece> blackBishop{new Bishop{PieceColor::BLACK, bishopsCoords[2]}};
    piecesMap.insert({bishopsCoords[2], std::move(blackBishop)});
    blackBishop.reset(new Bishop{PieceColor::BLACK, bishopsCoords[3]});
    piecesMap.insert({bishopsCoords[3], std::move(blackBishop)});
    //====== end of bishops =======

    //========== queens ==========
    shared_ptr<Piece> whiteQueen{new Queen{PieceColor::WHITE, queensCoords[0]}};
    piecesMap.insert({queensCoords[0], std::move(whiteQueen)});

    shared_ptr<Piece> blackQueen{new Queen{PieceColor::BLACK, queensCoords[1]}};
    piecesMap.insert({queensCoords[1], std::move(blackQueen)});
    //====== end of queens =======

    //======== kings ==========
    shared_ptr<Piece> whiteKing{new King{PieceColor::WHITE, kingsCoords[0]}};
    this->whiteKing = whiteKing;
    piecesMap.insert({kingsCoords[0], std::move(whiteKing)});

    shared_ptr<Piece> blackKing{new King{PieceColor::BLACK, kingsCoords[1]}};
    this->blackKing = blackKing;
    piecesMap.insert({kingsCoords[1], std::move(blackKing)});
    //===== end of kings ======

    //===== Other locations ======
    for (uint8_t i = 0; i < boardSize; i++)
    {
        for (uint8_t j = 2; j < boardSize - 2; j++)
        {
            piecesMap.insert({{i, j}, nullptr});
        }
    }
}

shared_ptr<Piece> Board::getPieceAt(const Coordinates &coord) const
{
    if (!isCoordinatesInBoard(coord))
    {
        throw BadCoord{};
    }
    return piecesMap.at(coord);
}

const Coordinates &Board::movePiece(const Coordinates &oldCoord, const Coordinates &newCoord)
{
    if (piecesMap.at(newCoord) != nullptr || piecesMap.at(oldCoord) == nullptr)
    {
        throw BadMove();
    }

    // Move the piece in the board's hash map
    piecesMap.at(newCoord) = std::move(piecesMap.at(oldCoord));

    // Move the piece itself
    piecesMap.at(newCoord)->coord = newCoord;

    return newCoord;
}

void Board::printBoard() const noexcept
{
    string dashedLine = "   ─";
    for (uint8_t i = 0; i < boardSize * 2; i++)
    {
        dashedLine += "─";
    }
    for (uint8_t j = 0; j < boardSize; j++)
    {
        if (j == 0) [[unlikely]]
        {
            PrettyPrint::simplePrintln("\n    a b c d e f g h");
            PrettyPrint::simplePrintln(dashedLine);
        }

        for (uint8_t i = 0; i < boardSize; i++)
        {
            auto piece = getPieceAt({i, j});
            if (i == 0) [[unlikely]]
            {
                PrettyPrint::simplePrint(std::to_string(j) + "  ");
                PrettyPrint::simplePrint("│");
            }
            PrettyPrint::simplePrint(piece == nullptr ? " " : piece->getCharacter());
            PrettyPrint::simplePrint("│");

            if (i == 7) [[unlikely]]
            {
                PrettyPrint::simplePrint("  " + std::to_string(j));
            }
        }
        PrettyPrint::simplePrint("\n");
        PrettyPrint::simplePrintln(dashedLine);
        if (j == boardSize - 1) [[unlikely]]
        {
            PrettyPrint::simplePrintln("    a b c d e f g h\n");
        }
    }
}

[[nodiscard]] vector<Coordinates> Board::getNonEmptyCoords() const noexcept
{
    vector<Coordinates> result;
    for (auto &[k, v] : piecesMap)
    {
        if (v != nullptr)
            result.push_back(k);
    }
    return result;
}

[[nodiscard]] vector<shared_ptr<Piece>> Board::getPieces(const PieceColor color) const noexcept
{
    vector<shared_ptr<Piece>> result;
    for (auto &[k, v] : piecesMap)
    {
        if (v != nullptr && v->getPieceColor() == color)
            result.push_back(v);
    }
    return result;
}

[[nodiscard]] Coordinates Board::createCoord(const string &x, const string &y)
{
    if (!(x.size() == 1 && y.size() == 1))
        throw BadCoord();

    char xc = tolower(x.at(0));
    char yc = tolower(y.at(0));

    if (!(xc <= 'h' && xc >= 'a' && yc <= '7' && yc >= '0'))
        throw BadCoord();

    return Coordinates{static_cast<uint8_t>(xc - 'a'), static_cast<uint8_t>(yc - '0')};
}

bool Board::checkForDraw() const noexcept
{
    return getNonEmptyCoords().size() == 2; // Just two kings left
}

vector<Coordinates> Board::diagonalMoveCreator(Coordinates coord, PieceColor color, int8_t start, int8_t end, int8_t yMult) const
{
    vector<Coordinates> result;
    int8_t step = (start) > (end) ? -1 : 1;

    for (int8_t i = start; i <= abs(end); i += step)
    {
        int8_t j = i * yMult;
        const Coordinates newCoord{static_cast<uint8_t>(i + coord.getX()),
                                   static_cast<uint8_t>(j + coord.getY())};
        if (!isCoordinatesInBoard(newCoord))
            continue;

        auto coordPiece = getPieceAt(newCoord);
        if (coordPiece == nullptr)
        {
            result.push_back(newCoord);
            continue;
        }

        if (color != coordPiece->getPieceColor())
        {
            result.push_back(newCoord);
            break;
        }

        if (color == coordPiece->getPieceColor())
        {
            break;
        }
    }
    return result;
}

vector<Coordinates> Board::getDiagonalMoves(Coordinates coord, PieceColor color) const
{
    vector<Coordinates> diagCoords, temp;
    temp = diagonalMoveCreator(coord, color, 1, boardSize - 1, 1);
    diagCoords.insert(diagCoords.cend(), temp.cbegin(), temp.cend());

    temp = diagonalMoveCreator(coord, color, 1, boardSize - 1, -1);
    diagCoords.insert(diagCoords.cend(), temp.cbegin(), temp.cend());

    temp = diagonalMoveCreator(coord, color, -1, 1 - boardSize, 1);
    diagCoords.insert(diagCoords.cend(), temp.cbegin(), temp.cend());

    temp = diagonalMoveCreator(coord, color, -1, 1 - boardSize, -1);
    diagCoords.insert(diagCoords.cend(), temp.cbegin(), temp.cend());

    return diagCoords;
}

vector<Coordinates> Board::directMoveCreator(Coordinates coord, PieceColor color, int8_t i_start, int8_t i_end, int8_t i_step, bool xOry) const
{
    vector<Coordinates> result;
    int8_t x = 0, y = 0;
    if (xOry)
        x++;
    else
        y++;

    for (int8_t i = i_start; i <= abs(i_end); i += i_step)
    {
        Coordinates newCoord{(uint8_t)(coord.getX() + x * i), (uint8_t)(coord.getY() + y * i)};
        if (!isCoordinatesInBoard(newCoord))
            continue;

        auto newPiece = getPieceAt(newCoord);
        if (newPiece == nullptr)
        {
            result.push_back(newCoord);
            continue;
        }
        if (newPiece->getPieceColor() != color)
        {
            result.push_back(newCoord);
            break;
        }
        if (newPiece->getPieceColor() == color)
            break;
    }
    return result;
}

vector<Coordinates> Board::getDirectMoves(Coordinates coord, PieceColor color) const
{
    vector<Coordinates> directMoves, temp;
    temp = directMoveCreator(coord, color, 1, boardSize - 1, 1, true);
    directMoves.insert(directMoves.cend(), temp.cbegin(), temp.cend());

    temp = directMoveCreator(coord, color, -1, 1 - boardSize, -1, true);
    directMoves.insert(directMoves.cend(), temp.cbegin(), temp.cend());

    temp = directMoveCreator(coord, color, 1, boardSize - 1, 1, false);
    directMoves.insert(directMoves.cend(), temp.cbegin(), temp.cend());

    temp = directMoveCreator(coord, color, -1, 1 - boardSize, -1, false);
    directMoves.insert(directMoves.cend(), temp.cbegin(), temp.cend());

    return directMoves;
}
