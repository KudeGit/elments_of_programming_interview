#include <iostream>
#include <stack>
#include <unordered_map>
#include "../utils.hpp"

int max_length_with_matching_parenthesis (const std::string& str)
{
    std::stack<char> open_par_pos;
    int last_good_start = 0;
    int max_length = 0;
    for (int i = 0; i < str.size(); ++i) {
        if(str[i] == '(') {
            open_par_pos.push(i);
        } else {
            if (open_par_pos.empty()) {
                last_good_start = i + 1;
            } else {
                open_par_pos.pop();
                auto curr_start = open_par_pos.empty() ? 
                    last_good_start  - 1: open_par_pos.top();
                max_length = std::max (max_length, i - curr_start);
            }
        }
    }
    return max_length;
}


int main (void)
{
    std::unordered_map<std::string, int> test = {
        {"((())()(()", 6},
        {"((())()(()))", 12},
        {"))))))((())()(()", 6},
        {"((())))(())()()(())", 12},
        {"(())())))))()()()()", 8}
    };
    for (const auto& t: test) {
        auto l = max_length_with_matching_parenthesis(t.first);
        if (l != t.second) {
            std::cout << "error: " << t.first << ": expected " <<
                t.second << ", got : " << l << std::endl;
        }
    }
    return 0;
}
