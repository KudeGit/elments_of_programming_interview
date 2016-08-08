#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "../utils.hpp"

//0123456
//bedbathandbeyond


std::vector<std::string> is_concatenation (
        const std::string& str,
        const std::unordered_set<std::string> dict) 
{
    std::vector<int> L(str.size() + 1, 0);
    for (int i = 1;  i <= str.size(); ++i) {
        auto curr_sub_str = str.substr(0, i);
        if (dict.find(curr_sub_str) != dict.end()) {
            L[i] = i;
        }
        for (int j = 1; j <= i && L[i] == 0; ++j) {
            auto leftover = str.substr(j, i - j);
            if (L[j] != 0) {
                if (dict.find(leftover) != dict.end()) {
                    L[i] = i - j;
                }
            }
        }
    }
    std::vector<std::string> res;
    int i = str.size();
    if(L.back() > 0) {
        int i = str.size();
        while (i > 0) {
            auto s = str.substr(i - L[i], L[i]);
            i -= L[i];
            res.push_back(s);
        }
    }

    return res;

}


int main (void)
{
    std::unordered_set<std::string> dict = {
        "bed", "bath", "beyond", "and"
    };

    std::string str("bedbathandbeyond");
    auto res = is_concatenation(str, dict);
    std::cout << res << std::endl;
    return 0;
}

