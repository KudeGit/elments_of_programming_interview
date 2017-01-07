#include<iostream>
#include <vector>
#include <limits>


int gas_pump (const std::vector<int>& G, const std::vector<int>& D)
{
    if (G.size() != D.size()) {
        return -1;
    }
    auto S = 0;
    auto start = -1;
    auto Smin = std::numeric_limits<int>::max();
    for (auto i = 0; i < G.size(); ++i) {
        S += G[i] - D[i];
        if (Smin > S) {
            S = Smin;
            start = (i+1) % G.size();
        }
    }
    return S < 0 ? -1 : start;
}


int main (void)
{
    //tested on leetcode
    return 0;

}
