#include <iostream>
#include <vector>

int majority_element (const std::vector<int>& N)
{
    auto candidate = N[0];
    auto n_candidate = 0;
    for (const auto n: N) {
        n_candidate = candidate == n ? +1 : -1;
        if (n_candidate == 0) {
            candidate = n;
            n_candidate = 1;
        }
    }
    return n_candidate;
}
int main(void)
{
    //tested on leetcode
    return 0;
}
