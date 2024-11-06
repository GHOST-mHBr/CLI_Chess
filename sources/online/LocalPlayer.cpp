#include "LocalPlayer.hpp"
#include "AbstractOnlinePlayer.hpp"

LocalPlayer::LocalPlayer(const string& name, PlayerColor playerColor,
                         Game& game, TCPSocket& socket)
    : AbstractOnlinePlayer(name, playerColor, game, socket) {}

void LocalPlayer::play() {
    Coordinates from = getStartCoordinates();
    Coordinates to = getEndCoordinates();
    Player::play(from, to);
    sendCoordinates(from);
    sendCoordinates(to);
}
