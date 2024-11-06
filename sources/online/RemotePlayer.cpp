#include "RemotePlayer.hpp"
#include "../common/Game.hpp"
#include "../common/PrettyPrint.hpp"
#include "../common/exceptions/BadCoord.hpp"
#include "../common/exceptions/BadMove.hpp"
#include "AbstractOnlinePlayer.hpp"
#include <algorithm>
#include <stdexcept>

RemotePlayer::RemotePlayer(const string& name, PlayerColor playerColor,
                           Game& game, TCPSocket& socket)
    : AbstractOnlinePlayer{name, playerColor, game, socket} {}

const Coordinates RemotePlayer::getStartCoordinates() {
    PrettyPrint::prettyPrint("Waiting for coordinate...");

    uint8_t buffer[2]{0};
    auto len = socket.receiveData(buffer, 2);

    PrettyPrint::simplePrintln("got: (" + std::to_string((int)buffer[0]) +
                               ", " + std::to_string((int)buffer[1]) + ")");

    if (len == 2) {
        return Coordinates{static_cast<uint8_t>(buffer[0]),
                           static_cast<uint8_t>(buffer[1])};
    } else {
        throw std::logic_error{"[Critical] Bad coordinates"};
        exit(-1);
    }
}
