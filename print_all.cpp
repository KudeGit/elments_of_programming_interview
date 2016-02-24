#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "utils.hpp"



std::vector<std::string> tokenize (const std::string &str, int &pos)
{
    std::stringstream ss;
    std::vector<std::string> tokens;
    while(pos < str.size() && str[pos] != '}'){
        char c = str[pos];
        if (c == '{') {
            ss.str("");
        } else if(c == ',') {
            tokens.push_back(ss.str());
            ss.str("");
        } else {
            ss << c;
        }
        ++pos;
    }
    tokens.push_back(ss.str());
    ss.str("");
    ++pos;
    return tokens;
}


void print_all (const std::string &str, std::string current, int pos)
{
    for(; pos < str.size(); ++pos) {
        if(str[pos] == '{') {
            auto tokens = tokenize(str, pos);
            for (const auto& t: tokens) {
                std::string new_current(current);
                new_current += t;
                print_all(str, new_current, pos);
            }
            return;
        } else {
            current.push_back(str[pos]);
        }
    }
    std::cout << current << std::endl;
}

void print_all (const std::string& str)
{
    std::string current;
    print_all(str, current, 0);
}


int main (void)
{
    std::string test("{ciao,come,va}");
    int pos = 0;
    std::cout << tokenize(test, pos) << std::endl;
    std::string test1("Ciao, come va?");
    std::string test2("I love {pie,cake,fruit} with {ice cream, whip cream, jam}");
    print_all(test2);
    return 0;
}
