#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
//#include <functional>


class RomanNumber {
    static std::unordered_map<char, int> roman_to_decimal_map;
    static std::unordered_map<char, std::unordered_set<char>> exceptions_list;
//    static std::unordered_map<char, std::function<int(char, char)>> exceptions_lambda;
    private:
        std::string str;
    public:
        RomanNumber(std::string &s):str(s) {}
        RomanNumber(const char* s):str(s) {}
        int to_decimal();

};

std::unordered_map<char, int> RomanNumber::roman_to_decimal_map = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

std::unordered_map<char, std::unordered_set<char>> RomanNumber::exceptions_list = {
    {'I', {'X', 'V'}},
    {'X', {'L', 'C'}},
    {'C', {'M', 'D'}}, 
    {'L', {}},
    {'D', {}},
    {'V', {}},
    {'M', {}}};


int RomanNumber::to_decimal ()
{
    int res = 0;
    for (int i = 0; i < str.size(); ++i) {
        if(i + 1 < str.size()) {
            if(exceptions_list[str[i]].find(str[i+1]) != exceptions_list[str[i]].end()) {
                res += roman_to_decimal_map[str[i+1]] -
                    roman_to_decimal_map[str[i]];
                ++i;
            } else {
                res += roman_to_decimal_map[str[i]];
            }
        } else {
            res += roman_to_decimal_map[str[i]];
        }
    }
    return res;
}


int main (void)
{
    RomanNumber test("LIX");
    std::cout << test.to_decimal() << std::endl;
    return 0;

}
