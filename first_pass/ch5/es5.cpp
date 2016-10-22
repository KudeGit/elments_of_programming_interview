#include <iostream>
#include <string>
#include "../utils.hpp"

int sum (int a, int b)
{
    if (b == 0) {
        return a;
    }

    if(a == 0) {
        a = b;
        b = 0;
        return a;
    }

    int carry = (a & b) << 1;
    a ^= b;
    return sum(a,carry);
}

//get the negative without '-'
int get_negative(int b)
{
    b = ~b;
    b = sum(b,1);
    return b;
}

int multiply(int a, int b) 
{
    bool is_negative = false;
    if(b < 0) {
        is_negative = true;
        b = get_negative(b);
    }
    int res = 0;
    for (; b > 0; --b) {
        res = sum(res, a);
    }
    if(is_negative) {
        res = get_negative(res);
    }
    return res;
}


int multiply_faster (int a, int b)
{
    int res = 0;
    bool a_negative = a < 0;
    bool b_negative = b < 0;
    if(a_negative) {
        a = get_negative(a);
    }
    if(b_negative) {
        b = get_negative(b);
    }
    while(b) {
        if (b & 0x01) {
            res = sum(res,a);
        }
        a <<= 1;    //a = 2*a
        b >>= 1;    //b = b/2
    }

    if (a_negative ^ b_negative) {
        res = get_negative(res);
    }
    return res;
}



int main (int argc, char *argv[])
{
    if(argc != 3) {
        error("usage: %s <a> <b>", argv[0]);
        return 1;
    }
    int a = std::stoi(std::string(argv[1]));
    int b = std::stoi(std::string(argv[2]));
    int e = multiply_faster(a, b);
    print(e);
    return 0;
}
