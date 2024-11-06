#include "TCPClient.hpp"

#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <thread>

TCPClient::TCPClient() : myFd{0}, serverAddress{} { initSocket(); }

TCPClient::TCPClient(const string& ip, uint16_t port) : myFd{0}, serverAddress{} {
    serverAddress.sin_family = AF_INET;
    if (inet_aton(ip.c_str(), &serverAddress.sin_addr) == 0) {
        // TODO replace this with a suitable error checking loop
        throw std::invalid_argument("Got a bad value for IP");
    }
    serverAddress.sin_port = htons(port);
    initSocket();
}

void TCPClient::initSocket() {
    myFd = socket(PF_INET, SOCK_STREAM, 0);
    if (myFd < 0) {
        throw std::runtime_error(
            "Unkown error occurred while trying to create a socket");
    }
}

void TCPClient::setPortAndIp(const string& ip, uint16_t port) {
    serverAddress.sin_family = AF_INET;
    if (inet_aton(ip.c_str(), &serverAddress.sin_addr) == 0) {
        // TODO replace this with a suitable error checking loop
        throw std::invalid_argument("Got a bad value for IP");
    }
    serverAddress.sin_port = htons(port);
}

bool TCPClient::connectToServer() {
    return connect(myFd, (struct sockaddr*)&serverAddress,
                   sizeof(serverAddress)) == 0;
}

ssize_t TCPClient::sendData(const uint8_t* buffer, size_t len) const {
    uint8_t * clean_buffer = new uint8_t[len];
    memcpy(clean_buffer , buffer, len);

    for(auto c = clean_buffer ; c < clean_buffer+len ; c++){
        if ( *c == '\n') {
            (*c)=0;
            len = c-clean_buffer+1;
            break;
        }
    }    
    
    // fd_set* fds = new fd_set;
    // FD_ZERO(fds);
    // FD_SET(myFd, fds);
    // int done = -1;
    // do {
        // done = select(100, fds, NULL, NULL, NULL);
        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // } while (done < 0);

    return send(myFd, clean_buffer, len, 0);
}

ssize_t TCPClient::sendData(const string& data) const {
    return sendData((uint8_t*)data.c_str(), data.size());
}

ssize_t TCPClient::receiveData(uint8_t* buffer, size_t len) {
    std::fill(buffer, buffer + len, 0);
    return recv(myFd, buffer, len, 0);
}
