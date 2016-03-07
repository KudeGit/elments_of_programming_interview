#include <iostream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>

std::unordered_set<char> chars_to_store = {'(', '[', '{'};

std::unordered_map<char, char> char_map = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};

bool pbb_matched (const std::string& str)
{
    std::stack<char> s;
    for (const auto& c: str) {
        if(chars_to_store.find(c) != chars_to_store.end()) {
            s.push(c);
        } else if (char_map.find(c) != char_map.end()) {
            if(s.empty() || s.top() != char_map[c]) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty() == true;
}


int main (void)
{
    std::unordered_map<std::string, bool> strs = {
        {"()[]{()()}", true},
        {"()", true},
        {"[[]]", true},
        {"(){{{{{{{[]}}}}}}}", true},
        {"(", false},
        {"[][][(()][][]", false},
        {"]", false}
    };

    for (const auto& str: strs) {
        if(pbb_matched(str.first) != str.second) {
            std::cout << str.first << std::endl;
        }
    }
    return true;

}
