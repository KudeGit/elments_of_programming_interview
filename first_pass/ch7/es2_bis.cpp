#include <iostream>
#include <string>
#include <unordered_map>
#include "../utils.hpp"

void apply_rules (std::string& str, 
        std::unordered_map<char, std::string> rules)
{
    int new_length = 0;
    int old_length = str.size();
    for (const auto& s: str) {
        if (rules.find(s) == rules.end()) {
            new_length += 1;
        } else {
            new_length += rules[s].size();
        }
    }
    if (new_length > old_length) {
        str.resize(new_length);
    }
    int i = old_length - 1, j = new_length - 1;
    while (i >= 0 && j >= 0) {
        if(rules.find(str[i]) == rules.end()) {
            str[j--] = str[i--];
        } else {
            for (int k = rules[str[i]].size() - 1; k >= 0; --k) {
                str[j--] = rules[str[i]][k];
            }
            --i;
        }
    }
    if(new_length < old_length) {
        str.resize(new_length);
    }
    return;
}



int main (void)
{
    std::unordered_map<char, std::string> rules = {
        {'a', "dd"},
        {'b',  ""}
    };
   // std::string str1("a");
   // std::cout << str1 << " => ";
   // apply_rules(str1, rules);
   // std::cout << str1 << std::endl;

   // std::string str2("b");
   // std::cout << str2 << " => ";
   // apply_rules(str2, rules);
   // std::cout << str2 << std::endl;

    std::string str3("abcdaa");
    std::cout << str3 << " => ";
    apply_rules(str3, rules);
    std::cout << str3 << std::endl;


    return 0;
}
