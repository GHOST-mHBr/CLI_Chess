#include "PrettyPrint.hpp"
#include <thread>
#include <chrono>

void PrettyPrint::printCharsWithDelay(unsigned int delay_ms, const string &text)
{
    for (char c : text)
    {
        printf("%c", c);
        fflush(stdout);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

void PrettyPrint::printLinesWithDelay(unsigned int delay_ms, const vector<string> lines)
{
    for (string line : lines)
    {
        cout << line << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

void PrettyPrint::prettyPrintLines(unsigned int charsDelay_ms, unsigned int eolDelay_ms, const vector<string> lines){
    for(string line: lines){
        PrettyPrint::printCharsWithDelay(charsDelay_ms, line);
        std::this_thread::sleep_for(std::chrono::milliseconds(eolDelay_ms-charsDelay_ms));
    }
}

void PrettyPrint::prettyPrint(unsigned int charsDelay_ms, unsigned int eolDelay_ms, const string& line){
    PrettyPrint::printCharsWithDelay(charsDelay_ms, line);
    std::this_thread::sleep_for(std::chrono::milliseconds(eolDelay_ms-charsDelay_ms));
}

vector<string> PrettyPrint::convertStringToLines(const string& text){
    vector<string> result;
    string line{""};
    for(char c: text){
        line += c;
        if(c == '\n') [[unlikely]] {
            result.push_back(line);
            line="";
        }
    }
    return result;
}

void PrettyPrint::simplePrintln(const string& text){
    cout<<text<<endl;
}

void PrettyPrint::simplePrint(const string& text){
    cout<<text;
    fflush(stdout);
}

const uint PrettyPrint::defaultCharsDelay = 120;
const uint PrettyPrint::defaultEolDelay = 400;
