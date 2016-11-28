#include <iostream>
#include <vector>
#include <algorithm>
#include "ch14.hpp"



int smallest_nonconstructible_change (std::vector<int>& coins)
{
    std::sort(coins.begin(), coins.end());
    int sum = 0;
    for (const auto c: coins) {
        if (c > sum + 1) {
            break;
        }
        sum += c;
    }
    return sum+1;

}
