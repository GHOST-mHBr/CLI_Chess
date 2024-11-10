#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <regex>
#include <unistd.h>

class TCPSocket {
public:
    const static std::regex ipv4_regex, port_regex;
    virtual void start() = 0;
    virtual ssize_t sendData(const uint8_t* buffer, size_t len) const = 0;
    virtual ssize_t receiveData(uint8_t* buffer, size_t len) = 0;
};
