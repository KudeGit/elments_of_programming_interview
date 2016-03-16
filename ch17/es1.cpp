#include <iostream>
#include <vector>
#include "../utils.hpp"

int tot_num_of_plays (const std::vector<int> plays, const int S)
{
    std::vector<int> K(S+1, 1);
    for (int s = 0; s <= S; ++s) {
        debug(s);
        for (const auto p: plays) {
            if (p <= s) {
                K[s] += K[s-p];
            }
        }
    }
    return K.back();
}

int main (void)
{
    std::vector<int> plays = {2, 3, 7};
    int nums = tot_num_of_plays (plays, 12);
    std::cout << nums << std::endl;
    return 0;
}
