#include <iostream>
#include <vector>
#include "../utils.hpp"

long int count_combinations (const std::vector<int>& plays,
        const int score)
{
    std::vector<int> S(score + 1, 0);
    S[0] = 1;
    for (const auto p: plays) {
        for (int s = p; s <= score; ++s) {
            S[s] += S[s-p];
        }
    }
    return S.back();
}

long int count_dispositions (const std::vector<int>& plays,
        const int score)
{
    std::vector<int> S(score + 1, 0);
    S[0] = 1;
    for (int s = 0; s <= score; ++s) {
        for (int i = 0; i < plays.size(); ++i) { 
            if (plays[i] >= s) {
                S[s] += S[plays[i] - s];
            }
        }
    }
    return S[score];
}

int main (void)
{
    std::vector<int> plays = {2,3,7};
    auto res = count_combinations(plays, 12);
    std::cout << "combinations: "  << res << std::endl;
    res = count_dispositions(plays, 12);
    std::cout << "permutations: "  << res << std::endl;

    return 0;
}
