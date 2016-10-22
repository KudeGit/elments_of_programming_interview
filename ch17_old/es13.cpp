#include <iostream>
#include <vector>

int get_max_height_helper (int c, int d, 
        std::vector<std::vector<int>>& F)
{
    if (d == 0 || c == 0) {
        return 0;
    } else if (c == 1) {
        return d;
    } else if (F[c][d] == -1) {
        F[c][d] = get_max_height_helper(c, d-1, F) +
            get_max_height_helper(c - 1, d - 1, F) + 1;
    }
    return F[c][d];
}

int get_max_height (int c, int d)
{
    std::vector<std::vector<int>> F(c + 1, std::vector<int>(d + 1, -1));
    return get_max_height_helper(c,d,F);
}


int main (void)
{
    auto res = get_max_height(3, 3);
    std::cout << res << std::endl;
    return 0;
}
