#include <iostream>
#include <string>
#include <cassert>

bool is_palindrome_permutation (const std::string& str)
{
    char counts[128] = {0};
    for (const auto s: str) {
        assert(s>= 0 && s < 128);
        ++counts[s];
    }
    bool is_odd = false;
    for (const auto& c: counts) {
        if (c & 0x01) {
            if(is_odd) {
                return false;
            }
            is_odd = true;
        }
    }
    return true;
}
