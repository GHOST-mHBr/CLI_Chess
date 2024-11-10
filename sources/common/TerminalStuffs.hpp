#pragma once
#include "PrettyPrint.hpp"
#include <cstdlib>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using std::cin;
using std::regex;
using std::regex_match;
using std::string;

class TerminalStuffs {
public:
    static void clearTerminal() noexcept { system("clear"); };

    template <typename T>
    [[nodiscard]] static T readFromInput(const std::string&& prompt,
                                         const std::regex& regex) {
        string str;
        T result;
        bool done = false;

        do {
            PrettyPrint::simplePrint(prompt);
            getline(cin, str);
            std::istringstream iss{str};
            iss >> result;
            done = !(iss.fail() || !iss.eof()) && regex_match(str, regex);
            if (!done)
                PrettyPrint::simplePrintln("Error, try again");

        } while (!done);
        return result;
    }
};
