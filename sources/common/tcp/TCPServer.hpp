#pragma once

#include "TCPSocket.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

using std::size_t;
using std::string;

class TCPServer: public TCPSocket
{
private:
    int hostFd, clientFd;
    sockaddr_in clientAddress, hostAddress;

    bool startServer();

public:
    TCPServer();
    TCPServer(uint16_t port);
    ssize_t sendData(const string &data) const;
    void setPort(uint16_t port);
    virtual void start()override {startServer();}
    virtual ssize_t sendData(const uint8_t *buffer, size_t length)const override;
    virtual ssize_t receiveData(uint8_t *buffer, size_t length) override;
};
