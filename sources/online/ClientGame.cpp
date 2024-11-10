#include "ClientGame.hpp"
#include "../common/PrettyPrint.hpp"
#include "../common/TerminalStuffs.hpp"
#include "LocalPlayer.hpp"
#include "RemotePlayer.hpp"
#include <cstdint>
#include <memory>

ClientGame::ClientGame():Game(nullptr , nullptr) {}

void ClientGame::initializeSocket() {
    std::string ip = TerminalStuffs::readFromInput<std::string>(
        std::string("Enter the ip you want to connect to: ") , TCPSocket::ipv4_regex);

    uint16_t port = TerminalStuffs::readFromInput<uint16_t>(
        "Enter the port you want to connect to: ", TCPSocket::port_regex);

    clientSocket = TCPClient(ip, port);
    clientSocket.start();
}

void ClientGame::initLocalPlayer() {
    std::string name =
        TerminalStuffs::readFromInput<std::string>("Enter a name for the player: ", std::regex(R"(^\b.*\b$)"));

    blackPlayer = std::make_unique<LocalPlayer>(name, PlayerColor::BLACK, *this, clientSocket);
}

void ClientGame::initRemotePlayer() {
    zeroBuffer();
    auto len = clientSocket.receiveData(buffer, buffer_size);
    string name{reinterpret_cast<char*>(buffer)};
    if (len > 0) {
        whitePlayer = std::make_unique<RemotePlayer>(name, PlayerColor::WHITE,
                                                     *this, clientSocket);
    }
    PrettyPrint::simplePrint("Opponent's name: " + name);
}

void ClientGame::initGame() {
    buffer = new uint8_t[buffer_size];
    initializeSocket();
    initLocalPlayer();
    clientSocket.sendData(blackPlayer->getName());
    initRemotePlayer();
}
