#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "../utils.hpp"


double pow_positive_exp (double a, int b)
{
    if (b == 0) {
        return 1;
    }

    if (b & 0x01) {
        return a * pow_positive_exp(a, b >> 1) * pow_positive_exp(a, b >> 1);
    } else {
        return pow_positive_exp(a, b >> 1) * pow_positive_exp(a, b>>1);
    }
}

double pow (double a, int b)
{
    bool b_negative = b < 0;
    if (a == 0 && b == 0) {
        throw std::invalid_argument("pow(0,0) is indeterminate");
        return 0;
    }
    if(a == 0) {
        return 0;
    }
    if (b == 0) {
        return 1;
    }

    if (b_negative) {
        b = -b;
    }
    double res = pow_positive_exp(a,b);
    if (b_negative) {
        res = 1/res;
    }
    return res;
}


int main (int argc, char* argv[])
{
    if (argc != 3) {
        error("usage: %s <base> <exponent>", argv[0]);
        return 1;
    }
    double a; 
    int b;

    std::stringstream ssa(argv[1]);
    std::stringstream ssb(argv[2]);
    ssa >> a;
    ssb >> b;


    try{
        double res =  pow(a,b);
        std::cout << "pow(" << a << ", " << b << ") = " << res << std::endl;
    } catch (const std::invalid_argument &ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
    }
    return 0;
}
