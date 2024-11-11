#include "Player.hpp"
#include "../common/PrettyPrint.hpp"
#include "../common/exceptions/BadCoord.hpp"
#include "../common/exceptions/BadMove.hpp"
#include "../common/tcp/TCPClient.hpp"
#include "../common/tcp/TCPServer.hpp"
#include "Coordinates.hpp"
#include "Game.hpp"
#include "TerminalStuffs.hpp"
#include <algorithm>
#include <regex>

Player::Player(const string name, PlayerColor playerColor, Game& game)
    : name(name), color(playerColor), game(game) {
    pieces = game.getBoard().getPieces(playerColor);
}

/**
 * @brief gets the start coordinates from a user for doing a movement
 */
[[nodiscard]] const Coordinates Player::getStartCoordinates() {
    return coordinatesPrompt("Select a coordinate: ");
}

/**
 * @brief gets the destination coordinates from a user for doing a movement
 */
[[nodiscard]] const Coordinates Player::getEndCoordinates() {
    return coordinatesPrompt("Enter destination coordinate: ");
}

[[nodiscard]] const Coordinates
Player::coordinatesPrompt(const string& promptMsg) const noexcept {
    string coordinates = TerminalStuffs::readFromInput<std::string>(
        promptMsg, std::regex("[a-h][0-7]"));
    return Coordinates{coordinates};
}

/**
 * @brief does a chess movement
 * @throws throws a BadMove exception in case the piecePtr was null
 */
void Player::doMove(shared_ptr<Piece>& piecePtr, const Coordinates& to) {
    if (piecePtr == nullptr) {
        throw BadMove();
    }
    auto result = std::find(pieces.cbegin(), pieces.cend(), piecePtr);
    if (result == pieces.cend()) {
        throw BadMove();
    }

    PieceColor fromColor = piecePtr->getPieceColor();
    Board& board = game.getBoard();
    const shared_ptr<Piece>& toPiece = board.getPieceAt(to);

    if (toPiece == nullptr) {
        board.movePiece(piecePtr->getCoordinates(), to);
        return;
    }

    PieceColor toColor = board.getPieceAt(to)->getPieceColor();

    if (fromColor != toColor && toPiece != board.getBlackKing() &&
        toPiece != board.getWhiteKing()) {
        board.removePiece(to);
        board.movePiece(piecePtr->getCoordinates(), to);
    }
}

void Player::play() {
    const Coordinates startCoord = getStartCoordinates();
    const Coordinates endCoord = getEndCoordinates();
    play(startCoord, endCoord);
}

void Player::play(const Coordinates& from, const Coordinates& to) {
    auto piecePtr = game.getBoard().getPieceAt(from);
    if (piecePtr == nullptr) {
        throw BadCoord();
    }
    if (game.validateMove(piecePtr, to)) {
        doMove(piecePtr, to);
    } else {
        throw BadMove();
    }
}
