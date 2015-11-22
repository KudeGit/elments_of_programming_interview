#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "../utils.hpp"

class Keypad {
    private:
        static std::unordered_map<char, std::string> keypad;
        void _generate_words(std::string& number, 
                int pos, std::string &current, std::vector<std::string> &res);
    public: 
        std::vector<std::string> generate_words (std::string& number);
        std::vector<std::string> generate_words (const char* number);
};
void Keypad::_generate_words(std::string &number, int pos, 
        std::string &current, std::vector<std::string> &res)
{
    if(pos == number.size()) {
        res.push_back(current);
    }
    for (auto& c: keypad[number[pos]]) {
        current[pos] = c;
        _generate_words(number, pos+1, current, res);
    }
}

std::vector<std::string> Keypad::generate_words (const char* number)
{
    std::string number_str(number);
    return generate_words(number_str);
}

std::vector<std::string> Keypad::generate_words (std::string& number) 
{
    std::vector<std::string> res;
    std::string current(number.size(), 0);
    _generate_words(number, 0, current, res);
    return res;
}

std::unordered_map<char, std::string> Keypad::keypad = {
    {'1', "1"}, 
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mnp"},
    {'7', "qrst"},
    {'8', "uvw"},
    {'9', "xyz"},
    {'0', "0"},
    {'*', "*"},
    {'#', "#"}};


int main (void) 
{
    Keypad k;
    auto strs = k.generate_words("23");
    std::cout << strs << std::endl;

    return 0;
}
