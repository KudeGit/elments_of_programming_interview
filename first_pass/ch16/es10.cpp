#include <iostream>
#include <vector>
#include "../utils.hpp"


void flip_bit (int& a, int pos)
{
    a ^= 1 << pos;
}

void get_next_code (const int n, const int k,
        std::vector<int>& all_codes,
        int& current)
{
    if (k == n) {
        all_codes.emplace_back(current);
        return;
    }
    get_next_code(n, k+1, all_codes, current);
    flip_bit(current, k);
    get_next_code(n, k+1, all_codes, current);
}


std::vector<int> compute_grey_code (int n)
{
    std::vector<int> all_codes;
    int current = 0;
    get_next_code(n, 0, all_codes, current);
    return all_codes;
}

int hamming_distance (int a, int b)
{
    int dh = 0;
    while (a || b) {
        if ( (a & 0x1) ^ (b & 0x1)) {
            ++dh;
        }
        a >>= 1; b >>= 1;
    }
    return dh;
}


int main (void)
{
    auto code = compute_grey_code(5);
    std::cout << code << std::endl;
    for (int i = 1; i < code.size(); ++i) {
        if (hamming_distance(code[i], code[i-1]) != 1) {
            std::cout << "distance is not 1 between " << 
                code[i] << " and " << code[i-1] << std::endl;
        }
    }
    return 0;
}
