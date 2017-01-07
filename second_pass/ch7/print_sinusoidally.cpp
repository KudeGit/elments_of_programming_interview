#include <iostream>
#include <string>
#include <sstream>


void print_sinusoidally (const std::string& s)
{
    //print first line
    std::stringstream ss;
    ss << " ";
    for (int i = 1; i < s.size(); i+=4) {
        ss << s[i] << std::string(3, ' ');
    }
    std::cout << ss.str() << std::endl;
    ss.str("");
    for (int i  = 0; i < s.size(); i += 2) {
        ss << s[i] << std::string(1, ' ');
    }
    std::cout << ss.str() << std::endl;
    ss.str("");
    ss << "   ";
    for (int i  = 3; i < s.size(); i += 4) {
        ss << s[i] << std::string(3, ' ');
    }
    std::cout << ss.str() << std::endl;
}


int main (void)
{
    print_sinusoidally("Hello_World!");
    return 0;
}
