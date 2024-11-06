#pragma once

#include "Board.hpp"
#include "Coordinates.hpp"
#include "Pieces/Piece.hpp"
#include "PlayerColor.hpp"
#include <memory>
#include <string>
#include <vector>

class Game;
class ClientGmae;
class ServerGame;

using std::shared_ptr;
using std::string;
using std::vector;

class Player {
    // Private constructor but friend with the Game class, makes this class only
    // constructable by the Game class
    friend Game;
    friend ClientGmae;
    friend ServerGame;

private:
    /*!
    \param[in] piecePtr pointer to the piece to move
    \param[in] to destination of the piece
    \brief does a chess movement(attack or relocation) without validity checking
    */
    void doMove(shared_ptr<Piece>& piecePtr, const Coordinates& to);

protected:
    string name;
    PlayerColor color;
    Game& game;
    /*!
    All player's pieces
    */
    vector<shared_ptr<Piece>> pieces;

    [[nodiscard]] const Coordinates
    coordinatesPrompt(const string& promptMsg) const noexcept;

    [[nodiscard]] const virtual Coordinates getStartCoordinates();

    [[nodiscard]] const virtual Coordinates getEndCoordinates();


public:
    Player(const string name, PlayerColor playerColor, Game& game);

    [[nodiscard]] const PlayerColor& getColor() const noexcept { return color; }

    [[nodiscard]] const string& getName() const noexcept { return name; }

    void setName(const string& newName) noexcept { name = newName; }

    virtual void play();
    
    void play(const Coordinates& from , const Coordinates& to);

};
