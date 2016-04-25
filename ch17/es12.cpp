#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../utils.hpp"

using dict_t = std::unordered_set<std::string>;

std::vector<std::string> compute_partition (const std::string &S, const dict_t dict)
{
    std::vector<int> K(1 + S.size(), 0);
    for (int i = 1; i <= S.size(); ++i) {
        auto word = S.substr(0, i);
        if (dict.find(word) != dict.end()) {
            K[i] = i;
        }
        for (int j = 1; j <= i && K[i] == 0; ++j) {
            if (K[j] != 0) {
                auto leftover = S.substr(j, i - j);
                if (dict.find(leftover) != dict.end()) {
                    K[i] = i - j;
                }
            }
        }
    }
    //debug(K);
    std::vector<std::string> res;
    if (K.back() > 0) {
        int j = S.size();
        while (j > 0) {
            //debug(j);
            //debug(K[j]);
            //debug(j - K[j]);
            auto word = S.substr(j - K[j], K[j]);
            //debug(word);
            res.push_back(word);
            j -= K[j];
        }
    }
    return res;
}


int main (void)
{
    dict_t dict = {"bed", "bath", "and", "beyond"};
    auto res = compute_partition("bedbathandbeyondbathandbath", dict);
    debug(res);
    return 0;
}
