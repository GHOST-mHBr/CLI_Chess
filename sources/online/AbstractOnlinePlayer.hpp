#pragma once
#include "../common/Player.hpp"
#include "../common/tcp/TCPSocket.hpp"

class AbstractOnlinePlayer : public Player {

protected:
    const virtual Coordinates getStartCoordinates() override = 0;
    const virtual Coordinates getEndCoordinates() override = 0;
    TCPSocket& socket;

    bool sendCoordinates(const Coordinates& coord);

public:
    AbstractOnlinePlayer(const string& name, PlayerColor playerColor,
                         Game& game, TCPSocket& socket);
};
