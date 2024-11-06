#pragma once
#include "../common/Player.hpp"
#include "../common/tcp/TCPServer.hpp"
#include "AbstractOnlinePlayer.hpp"

class RemotePlayer : public AbstractOnlinePlayer {
private:
    const virtual Coordinates getStartCoordinates() override;
    const virtual Coordinates getEndCoordinates() override {
        return getStartCoordinates();
    };

public:
    RemotePlayer(const string& name, PlayerColor playerColor, Game& game,
                 TCPSocket& socket);

    // virtual void play() override;
};
