#include "ServerGame.hpp"
#include "../common/Player.hpp"
#include "../common/PrettyPrint.hpp"
#include "../common/TerminalStuffs.hpp"
#include "../common/exceptions/BadMove.hpp"
#include "LocalPlayer.hpp"
#include "RemotePlayer.hpp"

ServerGame::ServerGame() : Game(nullptr, nullptr) {}

void ServerGame::initializeSocket() {
    uint16_t portNumber = TerminalStuffs::readFromInput<uint16_t>(
        "Select the port to start server on: ", TCPSocket::port_regex);
    serverSocket = TCPServer{portNumber};
}

void ServerGame::startServer() { serverSocket.start(); }

void ServerGame::initializeLocalPlayer() {
    PrettyPrint::simplePrint("");
    string name =
        TerminalStuffs::readFromInput<string>("Enter a name for your player: ", std::regex(R"(\b.*\b)"));

    whitePlayer = std::make_unique<LocalPlayer>(name, PlayerColor::WHITE, *this, serverSocket);
    serverSocket.sendData(name);
}

void ServerGame::initializeRemotePlayer() {
    PrettyPrint::simplePrintln("Waiting for opponent...");
    zeroBuffer();
    auto len = serverSocket.receiveData(buffer, buffer_size);
    string name{(char*)buffer};
    if (len > 0) {
        blackPlayer = std::make_unique<RemotePlayer>(name, PlayerColor::BLACK,
                                                     *this, serverSocket);
    }
    PrettyPrint::simplePrintln("Opponent's name: " + name);
}

void ServerGame::initGame() {
    buffer = new uint8_t[buffer_size];
    initializeSocket();
    startServer();
    initializeLocalPlayer();
    initializeRemotePlayer();
}
