#include "ClientGame.hpp"
#include "../common/PrettyPrint.hpp"
#include "../common/tcp/TCPServer.hpp"
#include "../common/tcp/TCPClient.hpp"
#include "../common/TerminalStuffs.hpp"


using namespace std;

string whitePlayerName,blackPlayerName;

void printHeader(){
    vector<string> headerLines;
    headerLines.push_back("=====================");
    headerLines.push_back("||---- WELCOME ----||");
    headerLines.push_back("=====================");
    headerLines.push_back("\n");
    PrettyPrint::printLinesWithDelay(400, headerLines);
    PrettyPrint::prettyPrintLines(85, 300, PrettyPrint::convertStringToLines("This is a CLI chess game written in modern C++\nHope you enjoy it!\n\n"));
}

int main(){
    // printHeader();
    TerminalStuffs::clearTerminal();
    ClientGame game{};
    game.initGame();
    game.start();

    return 0;
}
