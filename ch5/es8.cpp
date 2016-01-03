#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "../utils.hpp"

struct Convert 
{
    static std::unordered_map<char, int> char_to_digit;
    static std::unordered_map<char, int> digit_to_char;
    static const std::string invalid_input_str;
    static const std::string invalid_base_value;
    std::string convert (const std::string& str, 
                         const int b1,
                         const int b2);
    int atoi (const std::string& str, const int base);
    std::string itoa(const int n, const int b);
};

const std::string Convert::invalid_input_str("string does not represent a valid number");
const std::string Convert::invalid_base_value("invalid base value");

int Convert::atoi(const std::string& str, const int b)
{
    int n = 0;
    int start = 0;
    bool is_negative = false;

    if (b < 2 || b > 16) {
        throw std::invalid_argument(invalid_base_value);
    }
    if(str[0] == '-') {
        start = 1;
        if(str.size() == 1) {
            throw std::invalid_argument(invalid_input_str);
        }
        is_negative = true;
    }
    for (int i = start; i < str.size(); ++i) {
        char c = toupper(str[i]);
        if(char_to_digit.find(c) == char_to_digit.end()) {
            throw std::invalid_argument(invalid_input_str);
        }

        int d = char_to_digit[c];
        if (d >= b) {
            throw std::invalid_argument(invalid_input_str);
        }
        n = n*b + d;
    }
    if (is_negative) {
        n = -n;
    }
    return n;
}
std::string Convert::itoa (int n, const int b)
{
    std::string res;
    bool is_negative;
    if (b < 2 || b > 16) {
        throw std::invalid_argument(invalid_base_value);
    }

    if(n < 0) {
        n = -n;
        is_negative = true;
    }

    while (n) {
        int d = n % b;
        if(digit_to_char.find(d) == digit_to_char.end()) {
            throw std::invalid_argument(invalid_input_str);
        }
        n /= b;
        res.push_back(digit_to_char[d]);
    }
    if(is_negative) {
        res.push_back('-');
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::string Convert::convert (const std::string& str, 
        const int b1,
        const int b2)
{
    try {
        int n = atoi (str, b1);
        return itoa(n, b2);
    } catch (const std::invalid_argument& ia) {
        throw ia;
    }
}

std::unordered_map<char, int> Convert::char_to_digit = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15}};


std::unordered_map<char, int> Convert::digit_to_char = {
    {0,  '0'},
    {1,  '1'},
    {2,  '2'},
    {3,  '3'},
    {4,  '4'},
    {5,  '5'},
    {6,  '6'},
    {7,  '7'},
    {8,  '8'},
    {9,  '9'},
    {10, 'A'},
    {11, 'B'},
    {12, 'C'},
    {13, 'D'},
    {14, 'E'},
    {15, 'F'}};



int main (int argc, char* argv[])
{
    if (argc != 4) {
        error("usage: %s number base1 base2", argv[0]);
        return 1;
    }
    std::string str(argv[1]);
    int base1 = std::stoi(std::string(argv[2]));
    int base2 = std::stoi(std::string(argv[3]));
    Convert convert;
    try {
        std::string res;
        res = convert.convert(str, base1, base2);
        std::cout << str << " in base " << base2 << " is " << res << std::endl;
    } catch(const std::invalid_argument& ia) {
        error("%s", ia.what());
        return 1;
    }
    return 0;
}

