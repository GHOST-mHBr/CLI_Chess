#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include "PrettyPrint.hpp"

using std::cin;
using std::string;

class TerminalStuffs {
public:
    static void clearTerminal() noexcept{system("clear");};

    template <typename T>
    [[nodiscard]] static T readFromInput() noexcept{
        string str;
        getline(cin, str);
        std::istringstream iss(str);
        T result;

        bool done = false;
        do {
            iss >> result;
            done = !(iss.fail() || !iss.eof());
            if (!done) {
                PrettyPrint::simplePrintln("Error, try again");
            }
        } while (!done);

        return result;
    }

    template <typename T>
    [[nodiscard]] static T readFromInput(std::string&& prompt) noexcept{
        PrettyPrint::simplePrint(prompt);
        return readFromInput<T>();
    }
};
