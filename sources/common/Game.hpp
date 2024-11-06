#pragma once

#include "Board.hpp"
#include "Pieces/Piece.hpp"
#include "Player.hpp"

enum class GameResult { WHITE_WIN, DRAW, WHITE_LOSE, UNDEFINED };

class Game {
private:
    const uint8_t boardSize = 8;
    void createUsers();

protected:
    Board board{boardSize};
    unique_ptr<Player> whitePlayer, blackPlayer;
    GameResult result{GameResult::UNDEFINED};

protected:
    virtual void loop();

public:
    // white player resides on the top and does the first move
    Game();
    Game(unique_ptr<Player> whitePlayer, unique_ptr<Player> blackPlayer);
    bool checkForDraw();
    bool validateMove(shared_ptr<Piece>& pieceToMove,
                      const Coordinates& endCoord);

    Board& getBoard() { return board; }

    virtual void initGame();

    virtual void start();

    [[nodiscard]] bool isChecked(const PlayerColor color) const noexcept;

    [[nodiscard]] bool isCheckMated(const PlayerColor color) noexcept;

    /**
     * @param[in] piecePtr pointer to the piece to move
     * @param[in] coord destination of the piece
     * @brief checks if a movement cause check
     * @note this is not a const function because with the current design, we
     * have to move a piece and then check if it cause a check state.
     */
    [[nodiscard]] bool doesMoveCauseCheck(shared_ptr<Piece>& piecePtr,
                                          const Coordinates& coord) noexcept;
};
