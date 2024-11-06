#pragma once
#include <stdexcept>

using std::string;

class BadMove:public std::logic_error{

    public:
        BadMove(string& msg):std::logic_error(msg){}
        BadMove():std::logic_error(""){}

        const char* what()const throw(){
            return "Try to do a bad move";
        }
};
