#include "TCPServer.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <unistd.h>

using std::cout;
using std::endl;

TCPServer::TCPServer() : clientFd{0}, hostFd{0}, hostAddress{} {}

TCPServer::TCPServer(uint16_t port) : clientFd{0}, hostAddress{} {
    hostAddress.sin_addr.s_addr =
        0; // Will get filled automatically after calling bind()
    hostAddress.sin_family = AF_INET;
    hostAddress.sin_port = htons(port);

    hostFd = socket(PF_INET, SOCK_STREAM, 0);
    if (hostFd < 0) {
        throw std::invalid_argument("Cannot create socket. fd < 0");
    }
}

// I don't know what should i call this function :(
// After 10 minutes still can't find a suitable name...
void TCPServer::setPort(uint16_t port) {
    hostAddress.sin_addr.s_addr = INADDR_ANY;
    hostAddress.sin_family = AF_INET;
    hostAddress.sin_port = htons(port);
}

bool TCPServer::startServer() {
    if (hostFd == 0) {
        hostFd = socket(PF_INET, SOCK_STREAM, 0);
        if (hostFd < 0) {
            throw std::invalid_argument("Cannot create socket. fd < 0");
        }
    }
    if (bind(hostFd, (sockaddr*)(&hostAddress), sizeof(sockaddr_in)) < 0) {
        throw std::invalid_argument(
            "Unkown error occured while trying to bind the socket");
    }
    if (listen(hostFd, 1) < 0) {
        throw std::invalid_argument(
            "Unkown error occured while listening for new connections");
    }
    socklen_t addrlen = sizeof(clientAddress);

    if ((clientFd = accept(hostFd, (sockaddr*)(&clientAddress), &addrlen)) <
        0) {
        throw std::invalid_argument(
            "Unkown error occurred while trying to accept new connection");
    } else {
        cout << "Got a connection with ip: "
             << inet_ntoa(clientAddress.sin_addr)
             << " and port: " << ntohs(clientAddress.sin_port) << endl;
    }

    return true;
}

ssize_t TCPServer::sendData(const uint8_t* buffer, size_t len) const {
    uint8_t * clean_buffer = new uint8_t[len];
    memcpy(clean_buffer , buffer, len);

    for(auto c = clean_buffer ; c < clean_buffer+len ; c++){
        if ( *c == '\n') {
            (*c)=0;
            len = c-clean_buffer+1;
            break;
        }
    }

    return send(clientFd, clean_buffer, len, 0);
}

ssize_t TCPServer::sendData(const string& data) const {
    ssize_t res = sendData((uint8_t*)data.c_str(), data.size());
    // fd_set* fds = new fd_set;
    // FD_ZERO(fds);
    // FD_SET(hostFd, fds);
    // int done = -1;
    // do {
    //     done = select(100, fds, NULL, NULL, NULL);
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // } while (done < 0);
    return res;
}

ssize_t TCPServer::receiveData(uint8_t* buffer, size_t len) {
    std::fill(buffer, buffer + len, 0);
    return recv(clientFd, buffer, len, 0);
}
