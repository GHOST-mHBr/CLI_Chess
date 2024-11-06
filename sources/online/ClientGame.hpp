#pragma once

#include "../common/Game.hpp"
#include "../common/tcp/TCPClient.hpp"

class ClientGame : public Game {
private:
    TCPClient clientSocket;
    void initializeSocket();
    void initLocalPlayer();
    void initRemotePlayer();
    const int buffer_size = 256;
    uint8_t* buffer;
    void zeroBuffer() {
        if (buffer)
            std::fill(buffer, buffer+buffer_size,0);
    }

public:
    ClientGame();
    virtual void initGame() override;
    virtual ~ClientGame() {
        if (buffer != nullptr)
            delete buffer;
    }
};
