#include "Game.hpp"
#include "Pieces/PieceColor.hpp"
#include "Player.hpp"
#include "PlayerColor.hpp"
#include "PrettyPrint.hpp"
#include "TerminalStuffs.hpp"
#include "exceptions/BadCoord.hpp"
#include "exceptions/BadMove.hpp"
#include <algorithm>
#include <iostream>

using std::cin;

Game::Game() {
    whitePlayer = nullptr;
    blackPlayer = nullptr;
}

Game::Game(unique_ptr<Player> whitePlayer, unique_ptr<Player> blackPlayer)
    : whitePlayer(std::move(whitePlayer)), blackPlayer(std::move(blackPlayer)) {
}

void Game::initGame() { createUsers(); }

void Game::start() {
    while (result == GameResult::UNDEFINED) {
        loop();
    }

    if (result == GameResult::WHITE_WIN) {
        PrettyPrint::simplePrintln(whitePlayer->getName() + " wins");
    }
    if (result == GameResult::WHITE_LOSE) {
        PrettyPrint::simplePrintln(blackPlayer->getName() + " wins");
    }
    if (result == GameResult::DRAW) {
        PrettyPrint::simplePrintln("It a draw");
    }
}

void Game::loop() {
    auto playGame = [this](unique_ptr<Player>& player,
                           unique_ptr<Player>& enemy) {
        board.printBoard();
        PrettyPrint::printCharsWithDelay(100, "It\'s ");
        PrettyPrint::simplePrint(player->getName());
        PrettyPrint::prettyPrintln(100, 400, "\'s turn:");

        bool isPlayerDone = false;
        do {
            try {
                player->play();
                PrettyPrint::prettyPrintln("Done!");
                isPlayerDone = true;
            } catch (BadMove bm) {
                PrettyPrint::simplePrintln("Bad move, please try again");
            } catch (BadCoord bc) {
                PrettyPrint::simplePrintln("Bad coordinates, please try again");
            } catch (...) {
                PrettyPrint::simplePrintln("Unkown error, please try again");
            }
        } while (!isPlayerDone);

        if (isCheckMated(enemy->getColor())) {
            result = player->getColor() == PlayerColor::WHITE
                         ? GameResult::WHITE_WIN
                         : GameResult::WHITE_LOSE;
            return;
        }
        if (isChecked(enemy->getColor()))
            PrettyPrint::prettyPrintln(enemy->getColor() == PlayerColor::WHITE
                                         ? "white is checked"
                                         : "black is checked");

        TerminalStuffs::clearTerminal();
    };

    playGame(whitePlayer, blackPlayer);
    playGame(blackPlayer, whitePlayer);
}

bool Game::validateMove(shared_ptr<Piece>& pieceToMove,
                        const Coordinates& endCoord) {
    if (pieceToMove == nullptr) {
        return false;
    }

    auto validMoves = pieceToMove->getMoves(board);
    if (std::find(validMoves.cbegin(), validMoves.cend(), endCoord) !=
        validMoves.cend()) {
        if (!doesMoveCauseCheck(pieceToMove, endCoord)) {
            return true;
        }
    }
    return false;
}

bool Game::doesMoveCauseCheck(shared_ptr<Piece>& piecePtr,
                              const Coordinates& coord) noexcept {

    auto oldCoord = piecePtr->getCoordinates();
    auto destPiece{board.getPieceAt(coord)};
    auto& player = piecePtr->getPieceColor() == PieceColor::WHITE ? whitePlayer
                                                                  : blackPlayer;

    if (destPiece != nullptr)
        destPiece = destPiece->clone();

    if (piecePtr == nullptr)
        return false;

    auto srcPiece{piecePtr->clone()};

    auto undoMove = [&srcPiece, &destPiece, &oldCoord, &piecePtr, &player,
                     this]() {
        player->doMove(piecePtr, oldCoord);
        if (destPiece != nullptr) {
            board.setPieceAt(destPiece->getCoordinates(), destPiece);
        }
    };

    try {
        player->doMove(piecePtr, coord);
        if (isChecked(player->getColor())) {
            undoMove();
            return true;
        }
        undoMove();
    } catch (BadMove) {
    }

    return false;
}

bool Game::isCheckMated(const PlayerColor color) noexcept {
    if (isChecked(color)) {
        auto pieces = board.getPieces(color);
        for (auto& piece : pieces) {
            const Coordinates oldCoord = piece->getCoordinates();
            auto availableMoves = piece->getMoves(board);
            for (const auto& move : availableMoves) {
                if (!doesMoveCauseCheck(piece, move)) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool Game::isChecked(const PlayerColor color) const noexcept {
    PlayerColor enemyColor =
        (color == PlayerColor::WHITE ? PlayerColor::BLACK : PlayerColor::WHITE);
    const auto& kingCoord = color == PlayerColor::WHITE
                                ? board.getWhiteKing()->getCoordinates()
                                : board.getBlackKing()->getCoordinates();
    auto enemyPieces = board.getPieces(enemyColor);
    for (auto& enemyPiece : enemyPieces) {
        auto availableMoves = enemyPiece->getMoves(board);
        for (auto coord : availableMoves) {
            if (coord == kingCoord) {
                return true;
            }
        }
    }
    return false;
}

void Game::createUsers() {
    string playerName;
    PrettyPrint::simplePrint("Enter white player's name: ");
    std::getline(cin, playerName);
    whitePlayer =
        std::make_unique<Player>(playerName, PlayerColor::WHITE, *this);

    PrettyPrint::simplePrint("Enter black player's name: ");
    std::getline(cin, playerName);
    blackPlayer =
        std::make_unique<Player>(playerName, PlayerColor::BLACK, *this);
}
