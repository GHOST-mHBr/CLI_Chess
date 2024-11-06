#pragma once

#include "../common/Game.hpp"
#include "../common/tcp/TCPServer.hpp"
#include <cstring>

class ServerGame : public Game {
private:
    TCPServer serverSocket;
    void initializeSocket();
    void startServer();
    void initializeLocalPlayer();
    void initializeRemotePlayer();
    const int buffer_size = 256;
    uint8_t* buffer;

    void zeroBuffer() {
        if (buffer)
            std::fill(buffer, buffer + buffer_size, 0);
    }

public:
    ServerGame();
    virtual void initGame() override;

    ~ServerGame() {
        if (buffer != nullptr)
            delete buffer;
    }
};
