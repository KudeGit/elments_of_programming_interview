#include <iostream>
#include <string>
#include "../utils.hpp"


std::string look_and_say(const int n, int k, std::string current)
{
    if(k == n) {
        return current;
    }
    //debug(k);
    std::string next;
    int i = 0; 
    while (i < current.size()) {
        int count = 1;
        char current_char = current[i];
        //debug (current_char);
        while (i < current.size() && current[++i] == current_char) {
            ++count;
        }
        //debug(next);
        next.push_back('0'+count);
        next.push_back(current_char);
        //debug(next);
    }
    return look_and_say(n, k+1, next);
}

std::string  look_and_say (int n) 
{
    return look_and_say (n, 1, "1");
}


int main (void) 
{
    for (int i = 1; i <= 8; ++i) {
        std::cout << look_and_say(i) << std::endl;
    }
    return 0;
}
