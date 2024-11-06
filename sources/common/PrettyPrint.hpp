#pragma once

#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class PrettyPrint {
private:
    const static uint defaultCharsDelay, defaultEolDelay;

public:
    static void printCharsWithDelay(unsigned int delay_ms, const string& text);

    static void printLinesWithDelay(unsigned int delay_ms,
                                    const vector<string> lines);

    static void prettyPrintLines(unsigned int charsDelay_ms,
                                 unsigned int eolDelay_ms,
                                 const vector<string> lines);

    static void prettyPrint(unsigned int charsDelay_ms,
                            unsigned int eolDelay_ms, const string& line);

    static void prettyPrintln(unsigned int charsDelay_ms,
                              unsigned int eolDelay_ms, const string& line) {
        prettyPrint(charsDelay_ms, eolDelay_ms, line + "\n");
    }

    static void prettyPrint(const string& line) {
        prettyPrint(defaultCharsDelay, defaultEolDelay, line);
    }

    static void prettyPrintln(const string& line) {
        prettyPrint(defaultCharsDelay, defaultEolDelay, line + "\n");
    }

    static vector<string> convertStringToLines(const string& text);

    static void simplePrintln(const string& text);

    static void simplePrint(const string& text);
};
