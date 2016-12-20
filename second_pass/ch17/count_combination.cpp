#include <iostream>
#include <cassert>
#include <vector>

// 3+2 != 2+3
int count_permutation (const std::vector<int>& P, const int score)
{
    std::vector<int> S(score+1, 0);
    S[0] = 1;
    for (int i = 1; i < S.size(); ++i) {
        for (auto& p: P) {
            S[i] += i-p >= 0 ? S[i-p] : 0;
        }
    }
    return S[score];
}


int count_combination (const std::vector<int>& P, const int& score)
{
    std::vector<int> S(score+1, 0);
    S[0] = 1;
    for (auto& p: P) {
        for (int i = p; i < S.size(); ++i) {
            S[i] += S[i-p];
        }
    }
    return S[score];
}


int main (void)
{
    auto res = count_combination({2,3,7}, 6);
    std::cout << res << std::endl;
    return 0;
}
