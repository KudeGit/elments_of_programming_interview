#include <iostream>
#include <string>
#include "../utils.hpp"

std::string get_snake_str (const std::string& str)
{
    std::string snake_str(str.size(), ' ');
    int k = 0;
    for (int i = 1; i < str.size(); i += 4) {
        snake_str[k++] = str[i];
    }
    for (int i = 0; i < str.size(); i += 2) {
        snake_str[k++] = str[i];
    }
    for (int i = 3; i <str.size(); i+=4) {
        snake_str[k++] = str[i];
    }
    return snake_str;
}

int main (int argc, char* argv[])
{
    if (argc != 2) {
        error("ivalid usage: %s string", argv[0]);
        return -1;
    }
    std::cout << "The snalke string of \"" << argv[0] << "\" is \"" 
              << get_snake_str(argv[1]) << "\"" << std::endl;
    return 0;
}
