#pragma once

#include "TCPSocket.hpp"
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

using std::string;

class TCPClient : public TCPSocket
{
private:
    sockaddr_in serverAddress;
    uint16_t myFd;

    void initSocket();
    bool connectToServer();

public:
    TCPClient();
    TCPClient(const string &ip, uint16_t port);
    void setPortAndIp(const string& ip, uint16_t port);
    ssize_t sendData(const string &data) const;
    virtual void start() override { connectToServer(); }
    virtual ssize_t sendData(const uint8_t *buffer, size_t length) const override;
    virtual ssize_t receiveData(uint8_t *buffer, size_t length) override;
};
