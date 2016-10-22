#include <iostream>
#include "../utils.hpp"
#include <string>
#include <stdexcept>


int ssDecodeColID (const std::string& str)
{
    int id = 0;
    for (const auto c: str) {
        if (c < 'A' || c > 'Z') {
            throw std::invalid_argument("id not valid");
        }
        id = id * 26 + c - 'A' + 1;
    }
    return id;
}

int main (int argc, char* argv[]) 
{
    if (argc != 2) {
        error("usage: %s id", argv[0]);
        return 0;
    }
    std::string id_str(argv[1]);
    try {
        int id = ssDecodeColID(id_str);
        std::cout << id_str << " corresponds to " << id << std::endl;

    
    } catch (const std::invalid_argument& ia) {
        error("%s", ia.what());
        return 1;
    }
    return 0;
}


