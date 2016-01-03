#include <iostream>
#include <string>
#include "../utils.hpp"

unsigned int divide (unsigned int a, unsigned int b)
{
    int res = 0;
    while (a >= b) {
        int pow = 1;
        while ((b << pow) < (b << (pow + 1)) && ((b << pow) < a)) {
            ++pow;
        }
        res += 1 << (pow - 1);
        a -= b << (pow - 1);
    }
    return res;
}


int main (int argc, char* argv[])
{
    if (argc != 3) {
        error("usage: %s <a> <b>", argv[0]);
        return 1;
    }
    int a = std::stoi(std::string(argv[1]));
    int b = std::stoi(std::string(argv[2]));

    std::cout << divide(a,b) << " == " << a/b << std::endl;
    return 0;
}
