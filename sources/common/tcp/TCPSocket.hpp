#pragma once

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class TCPSocket{
    public:
        virtual void start() = 0;
        virtual ssize_t sendData(const uint8_t* buffer , size_t len) const = 0;
        virtual ssize_t receiveData(uint8_t* buffer, size_t len) = 0;
};
