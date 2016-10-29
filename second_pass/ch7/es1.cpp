#include <iostream>
#include <string>
#include <stdexcept>

int stringToInt (const std::string& str)
{
    if (str.empty()) {
        throw std::invalid_argument("empty string");
    }
    auto res = 0;
    auto res_prev = 0;
    auto is_negative = str[0] == '-' ? true : false;
    auto start = str[0] == '-' ? 1 : 0;

    for (int i = start; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            throw std::invalid_argument("string not valid");
        }
        if (res*10 + str[i] - '0' >= 0) {
            res = res*10 + str[i] - '0';
        } else {
            throw std::invalid_argument("string too long");
        }
    }
    return is_negative ? -res : res;
}


std::string intToString (int n)
{
    auto is_negative = false;
    std::string res;
    if (n < 0) {
        is_negative = true;
        n *= -1;
    }
    do {
        res.push_back('0' + (n%10));
        n /= 10;
    } while (n);
    if (is_negative) {
        res.push_back('-');
    }
    std::reverse(res.begin(), res.end());
    return res;
}
