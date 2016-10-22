#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"
#include <limits>
#include <numeric>


bool is_palidrome (const std::string& S)
{
    int i = 0, j = S.size() - 1;
    while (i < j) {
        if (S[i] != S[j]) {
            return false;
        }
        ++i; --j;
    }
    return true;
}

std::vector<std::string> min_palindrome_decomposition (const std::string& S)
{
    std::vector<int> K(S.size(), S.size());
    std::vector<int> T(S.size(), 1);
    for (int i = 0; i < S.size(); ++i) {
        //debug(i);
        if(is_palidrome(S.substr(0, i+1))) {
            K[i] = 1;
            T[i] = i+1;
        } else {
            for (int j = 0; j < i; ++j) {
                //debug(j);
                auto leftover = S.substr(j+1, i - j);
                //debug(leftover);
                if(is_palidrome(leftover)) {
                    if (K[i] > K[j] + 1) {
                        T[i] = i - j;
                        K[i] = K[j] + 1;
                    }
                }
            }
        }
        //debug(K);
        //debug(T);
    }
    int i = S.size();
    std::vector<std::string> res;
    while (i) {
        auto curr = S.substr(i - T[i-1], T[i-1]);
        //debug(curr);
        res.push_back(curr);
        i -= T[i-1];
        //debug(i);
    }
    return res;
}


int min_cuts (const std::string& S)
{
    std::vector<std::vector<bool>> K(S.size(), std::vector<bool>(S.size(), false));
    std::vector<int> T(S.size() + 1);
    std::iota(T.rbegin(), T.rend(), 0);
    for (int i = S.size() - 1; i >= 0; --i) {
        for (int j = i; j < S.size(); ++j) {
            if(S[i] == S[j] && (j - i < 2 || K[i+1][j-1])) {
                K[i][j] = true;
                T[i] = std::min(T[i], T[j+1]+1);
            }
        }
    }
    return T[0];
}

int main (void)
{
    //std::string S("0204451881");
    //std::string S("02044");
    //std::string S("anna");
    std::string S("1234");
    auto res = min_cuts(S);//min_palindrome_decomposition(S);
    debug(res);
    return 0;
}
