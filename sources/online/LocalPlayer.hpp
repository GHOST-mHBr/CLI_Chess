#pragma once
#include "AbstractOnlinePlayer.hpp"

class LocalPlayer : public AbstractOnlinePlayer {
private:
    const virtual Coordinates getEndCoordinates() override {
        return Player::getEndCoordinates();
    };
    const virtual Coordinates getStartCoordinates() override {
        return Player::getStartCoordinates();
    };

public:
    LocalPlayer(const string& name, PlayerColor playerColor, Game& game,
                TCPSocket& socket);
    virtual void play() override;
};
