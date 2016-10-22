#include <iostream>
#include <vector>
#include <limits>

int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
    long int S = 0, start = 0;
    long int Smin = std::numeric_limits<long>::max();
    int N = gas.size() == cost.size() ? gas.size() : 0;
    for (int i = 0; i < N; ++i) {
        S += gas[i] - cost[i];
        if (S < Smin) {
            Smin = S;
            start = i + 1;
        }
    }
    return S >= 0 ? start : -1;
}

//tested on leetcode:  Gas Station
int main (void)
{
    return 0;
}
