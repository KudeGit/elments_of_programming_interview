#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "../utils.hpp"


int min_cut (const std::string& S)
{
    std::vector<std::vector<bool>> is_pal(S.size(), std::vector<bool>(S.size(), false));
    std::vector<int> cuts(S.size()+1);
    std::iota(cuts.rbegin(), cuts.rend(), 0);
    for (int i = S.size(); i >= 0; --i) {
        for (int j = i; j < S.size(); ++j) {
            if (S[i] == S[j] && (i - j < 2 || is_pal[i+1][j-1])) {
                is_pal[i][j] = true;
                cuts[i] = std::min(cuts[i], cuts[j+1] + 1);
            }
        }
    }
    return cuts.front();
}


int main (void)
{
    std::string S("0204451881");
//    std::string S("annaotto");
//    std::string S("anna");
    auto res = min_cut(S);
    std::cout << res << std::endl;
    return 0;
}
