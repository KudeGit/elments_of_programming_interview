//Inspired:
//
//A Regular Expression Matcher
//Code by Rob Pike
//Exegesis by Brian Kernighan
//
//source at: http://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html


#include <iostream>
#include <string>
#include "../utils.hpp"


bool match_here(const std::string& str, int a, const std::string& regex, int b);

bool match_star (const char c, const std::string& str, int a, const std::string& regex, int b)
{
    do {
        if (match_here(str, a, regex, b)) {
            return 1;
        }
        ++a;
    } while (str[a] == c || c == '.');
}


bool match_here(const std::string& str, int a, const std::string& regex, int b)
{
    if (b == regex.size()) {
        return true;
    }
    if (b == regex.size() - 1 && regex[b] == '$') {
        return a == (str.size()-1);
    }
    if (regex.size() - b >= 2 && regex[b + 1] == '*') {
        return match_star(regex[b], str, a, regex, b+2);
    }
    if (a != str.size() && (str[a] == regex[b] || regex[b] == '.')) {
        return match_here(str, a + 1, regex, b + 1);
    }
    return false;
}


bool match (const std::string& str, const std::string& regex)
{
    if (regex.empty()) {
        throw std::invalid_argument("emoty regex");
    }
    if (regex[0] == '^') {
        return match_here (str, 1, regex, 0);
    }
    for (int i = 0; i < str.size(); ++i) {
        if(match_here(str, i, regex, 0)) {
            return true;
        }
    }
    return false;
}


int main (void)
{
    std::string str("ssssasadarrbsasasaacd");
    std::string regex("sssa*");
    int len = 0;
    std::cout << match(str, regex) << std::endl;

    return 0;
}
