#include "AbstractOnlinePlayer.hpp"

AbstractOnlinePlayer::AbstractOnlinePlayer(const string& name,
                                           PlayerColor playerColor, Game& game,
                                           TCPSocket& socket)
    : Player{name, playerColor, game}, socket{socket} {}

bool AbstractOnlinePlayer::sendCoordinates(const Coordinates& coord) {
    uint8_t data[] = {coord.getX(), coord.getY()};
    return (socket.sendData(data, 2) == 2);
}
