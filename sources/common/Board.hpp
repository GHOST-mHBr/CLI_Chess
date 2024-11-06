#pragma once

#include "Coordinates.hpp"
#include "CoordinatesHasher.hpp"
#include "Pieces/PieceColor.hpp"
#include "PlayerColor.hpp"
#include <map>
#include <memory>
#include <stdint.h>
#include <unordered_map>
#include <vector>

using std::map;
using std::shared_ptr;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

class Piece;

/*!
 * \note White pieces are at the top of the board
 */
class Board {
    // Private Fields
private:
    shared_ptr<Piece> whiteKing, blackKing;
    const uint8_t boardSize;
    unordered_map<const Coordinates, shared_ptr<Piece>, CoordinatesHasher>
        piecesMap;

    // Order of coordinates: white,[white],black,[black] from left to right
    const Coordinates rooksCoords[4] = {
        {0, 0},
        {static_cast<uint8_t>(boardSize - 1), 0},
        {0, static_cast<uint8_t>(boardSize - 1)},
        {static_cast<uint8_t>(boardSize - 1),
         static_cast<uint8_t>(boardSize - 1)}};

    const Coordinates knightsCoords[4] = {
        {1, 0},
        {static_cast<uint8_t>(boardSize - 2), 0},
        {1, static_cast<uint8_t>(boardSize - 1)},
        {static_cast<uint8_t>(boardSize - 2),
         static_cast<uint8_t>(boardSize - 1)}};

    const Coordinates bishopsCoords[4] = {
        {2, 0},
        {static_cast<uint8_t>(boardSize - 3), 0},
        {2, static_cast<uint8_t>(boardSize - 1)},
        {static_cast<uint8_t>(boardSize - 3),
         static_cast<uint8_t>(boardSize - 1)}};

    const Coordinates queensCoords[2] = {
        {3, 0}, {3, static_cast<uint8_t>(boardSize - 1)}};

    const Coordinates kingsCoords[2] = {
        {4, 0}, {4, static_cast<uint8_t>(boardSize - 1)}};

    // Private Functions
private:
    /*!
     \brief arranges all the pieces in their initial places
    */
    void arrangePieces();

    vector<Coordinates> diagonalMoveCreator(Coordinates coord, PieceColor color,
                                            int8_t start, int8_t end,
                                            int8_t yMult) const;
    vector<Coordinates> directMoveCreator(Coordinates coord, PieceColor color,
                                          int8_t i_start, int8_t i_end,
                                          int8_t i_step, bool xOry) const;

public:
    Board(const uint8_t size = 8);

    Board(Board& other) = delete;
    Board(Board&& other) = delete;

    [[nodiscard]] shared_ptr<Piece> getPieceAt(const Coordinates& coord) const;

    /*!
     * @param[in] piece the piece to move
     * @param[in] new coordinates to move the piece to
     * \returns returns the final coordinates that the piece placed to
     */
    [[nodiscard]] bool isEmpty(const Coordinates& coord) const noexcept {
        return piecesMap.at(coord) == nullptr;
    }

    /*!
     \param[in] where coordinates of the piece to remove
     \brief removes a piece from board
    */
    void removePiece(const Coordinates& where) noexcept {
        piecesMap.at(where) = nullptr;
    }

    void printBoard() const noexcept;

    const Coordinates& movePiece(const Coordinates& oldCoord,
                                 const Coordinates& newCoord);

    [[nodiscard]] const uint8_t getBoardSize() const noexcept {
        return boardSize;
    }

    [[nodiscard]] const shared_ptr<Piece>& getWhiteKing() const noexcept {
        return whiteKing;
    }

    [[nodiscard]] const shared_ptr<Piece>& getBlackKing() const noexcept {
        return blackKing;
    }

    [[nodiscard]] vector<Coordinates> getNonEmptyCoords() const noexcept;

    [[nodiscard]] vector<shared_ptr<Piece>>
    getPieces(const PieceColor color) const noexcept;

    [[nodiscard]] vector<shared_ptr<Piece>>
    getPieces(const PlayerColor color) const noexcept {
        return color == PlayerColor::WHITE ? getPieces(PieceColor::WHITE)
                                           : getPieces(PieceColor::BLACK);
    }

    [[nodiscard]] bool checkForDraw() const noexcept;

    [[nodiscard]] static Coordinates createCoord(const string& x,
                                                 const string& y);

    [[nodiscard]] bool
    isCoordinatesInBoard(const Coordinates& coord) const noexcept {
        return coord.getX() >= 0 && coord.getX() < boardSize &&
               coord.getY() >= 0 && coord.getY() < boardSize;
    }

    [[nodiscard]] vector<Coordinates> getDiagonalMoves(Coordinates coord,
                                                       PieceColor color) const;

    [[nodiscard]] vector<Coordinates> getDirectMoves(Coordinates coord,
                                                     PieceColor color) const;

    void setPieceAt(const Coordinates& coord, shared_ptr<Piece> piecePtr) {
        piecesMap.at(coord) = piecePtr;
    }

    ~Board() = default;
};
