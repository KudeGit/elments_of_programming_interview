#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../utils.hpp"


struct PhonePad {
    static std::unordered_map<char, std::string> num2chars;
    std::vector<std::string> numToStrings (const std::string& number);
    void numToStrings(const std::string& number, int pos, 
            std::string& current, std::vector<std::string>& acronyms);
};

std::unordered_map<char, std::string>
    PhonePad::num2chars = {{'1', ""},
                           {'2', "ABC"},
                           {'3', "DEF"},
                           {'4', "GHI"},
                           {'5', "JKL"},
                           {'6', "MNO"},
                           {'7', "PQRS"},
                           {'8', "TUV"},
                           {'9', "WXYZ"},
                          };


void PhonePad::numToStrings(const std::string& number, int pos, 
        std::string& current, std::vector<std::string>& acronyms)
{
    if (pos == number.size()) {
        acronyms.push_back(current);
        return;
    }
    for (int i = 0; i < num2chars[number[pos]].size(); ++i) {
        current.push_back(num2chars[number[pos]][i]);
        numToStrings(number, pos+1, current, acronyms);
        current.pop_back();
    }
}

std::vector<std::string> PhonePad::numToStrings (const std::string& number)
{
    std::vector<std::string> acronyms;
    std::string current;
    numToStrings(number, 0, current, acronyms);
    return acronyms;
}

int main (void)
{
    PhonePad pd;

    auto acronyms = pd.numToStrings("24");
    std::cout << acronyms << std::endl;

    return 0;
}
