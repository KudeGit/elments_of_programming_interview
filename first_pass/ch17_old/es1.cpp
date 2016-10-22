#include <iostream>
#include <vector>
#include "../utils.hpp"



int count_ways3 (const std::vector<int>& plays, const int score)
{
    std::vector<std::vector<int>> K(score+1, std::vector<int>(plays.size()+1, 0));

    for (int i = 0; i <= plays.size(); ++i) {
        K[0][i] = 1;
    }

    for (int i = 0; i <= score; ++i) {
        K[i][0] = 1;
    }
    for (int s = 1; s<= score; ++s) {
        for (int p = 0; p < plays.size(); ++p) {
            K[s][p+1] = (plays[p] <= s ? K[s-plays[p]][p] : 0) + // combination including play p
                (p > 0 ? K[s][p] : 0);
        }
        debug(K);
    }
    return K.back().back();
}

int count_ways (const std::vector<int>& plays, const int score)
{
    std::vector<std::vector<int>> K(score+1, std::vector<int>(plays.size(), 0));

    for (int i = 0; i < plays.size(); ++i) {
        K[0][i] = 1;
    }
    for (int s = 1; s<= score; ++s) {
        for (int p = 0 ; p < plays.size(); ++p) {
            K[s][p] = (plays[p] <= s ? K[s-plays[p]][p] : 0) + // combination including play p
                (p > 0 ? K[s][p-1] : 0);
        }
    }
    return K.back().back();
}


int count_ways_2 (const std::vector<int>& plays, const int score)
{
    std::vector<int> K(score + 1, 0);
    K[0] = 1; //1 way to get zero;
    for (const int p: plays) {
        for (int s = p; s <= score; ++s) {
            K[s] += K[s-p];
        }
    }
    return K.back();
}


int main (void)
{

    std::vector<int> plays = {2, 3, 7};
    std::cout << count_ways(plays, 12) << std::endl;
    std::cout << count_ways_2(plays, 12) << std::endl;
    std::cout << count_ways4(plays, 12) << std::endl;
    return 0;

}
