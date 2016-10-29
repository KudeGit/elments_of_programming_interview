#include <iostream>
#include <string>
#include <unordered_map>
#include "ch7.hpp"
#include "../../utils.hpp"


void replace_and_remove (std::string& str, const std::unordered_map<char, std::string>& rules)
{
    size_t new_len = 0;
    size_t old_len = 0;
    for (int i = 0, j = 0; i < str.size(); ++i) {
        auto it = rules.find(str[i]);
        if (it != rules.end()) {
            if (!it->second.empty()) {
                new_len += it->second.size();
                str[j++] = str[i];
                ++old_len;
            }
        } else {
            str[j++] = str[i];
            ++new_len;
            ++old_len;
        }
    }
    ////debug(new_len);

    if (new_len > str.size()) {
        while (str.size() < new_len) {
            str += std::string(new_len - str.size(), ' ');
            ////debug(str.size());
        }
    } else {
        while (str.size() > new_len) {
            str.pop_back();
        }
    }
    for (int i = old_len - 1, j = new_len -1; i >= 0; --i) {
        auto c = str[i];
        auto it = rules.find(c);
        if (it != rules.end()) {
            for (auto it2 = it->second.crbegin(); it2 != it->second.crend(); ++it2) {
                str[j--] = *it2;
                ////debug(j);
            }
        } else {
            str[j--] = str[i];
        }
    }
    //debug(str);
}



