#include <iostream>
#include <vector>


using namespace std;

int maxArea(vector<int>& H) {
    if (H.empty()) return 0;
    int l = 0;
    int r = H.size() - 1;
    auto maxWater = 0;
    while (l < r) {
        maxWater = std::max((r - l) * std::min(H[l], H[r]), maxWater);

        if (H[l] < H[r]) {
            ++l;
        } else if (H[l] > H[r]) {
            --r;
        } else {
            ++l; --r;
        }
    }
    return maxWater;
}
//tested with leetcode: 11. Container With Most Water
int main (void)
{
    return 0;
}
