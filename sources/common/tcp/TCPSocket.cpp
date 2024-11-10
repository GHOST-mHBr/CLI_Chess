#include "TCPSocket.hpp"
#include <regex>
#include <string>

const std::regex TCPSocket::ipv4_regex{std::string{R"(^((25[0-5]|(2[0-4]|1\d|[1-9]|)\d)\.?\b){4}$)"}};
const std::regex TCPSocket::port_regex{std::string{R"(^\b([1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])\b$)"}};
