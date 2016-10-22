#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct RomanNumber {
    static std::unordered_map<char, std::unordered_set<char>> exceptions;
    static std::unordered_map<char, int> values;
    std::string toRoman (int n);
    int toDecimal (const std::string& str);
};

std::unordered_map<char, int> 
RomanNumber::values = {{'I', 1},
                       {'V', 5},
                       {'X', 10},
                       {'L', 50},
                       {'C', 100},
                       {'M', 1000}};

std::unordered_map<char, std::unordered_set<char>>
RomanNumber::exceptions = {{'I', {'V', 'X'}},
                           {'X', {'L', 'C'}},
                           {'C', {'D', 'M'}}};

int RomanNumber::toDecimal (const std::string& str)
{
    int res = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (i + 1 < str.size()) {
            if (exceptions[str[i]].find(str[i+1]) != exceptions[str[i]].end()) {
                res += values[str[i+1]] - values[str[i]];
                ++i;
            } else {
                res += values[str[i]];
            }
        } else {
            res += values[str[i]];
        }
    }
    return res;
}


int main (void)
{
    std::string str("LIX");
    RomanNumber rn;
    std::cout << rn.toDecimal(str) << std::endl;
    return 0;
}
