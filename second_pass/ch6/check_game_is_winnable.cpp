#include <iostream>
#include <vector>

bool game_is_winnable (const std::vector<int>& P)
{
    auto max_pos = 0;
    for (int i = 0; i < P.size(); ++i) {
        if (max_pos < i) {
            return false;
        }
        max_pos = std::max(i+P[i], max_pos);
    }
    return true;
}

int main (void)
{
    //check leetcode
    return 0;
}
