#include <stdexcept>

using std::string;

class BadCoord:public std::logic_error{

    public:
        BadCoord(string& msg):std::logic_error(msg){}
        BadCoord():std::logic_error(""){}

        const char* what()const throw(){
            return "Invalid Coordinates";
        }
};
