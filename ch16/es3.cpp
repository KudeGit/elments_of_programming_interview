#include <iostream>
#include "../utils.hpp"
#include <vector>


bool is_feasible (const int candidate,
        const int k,
        const std::vector<int> rows)
{
    for (int  i = 0; i < k; ++i) {
        if(candidate == rows[i]) {
            return false;
        }
        if (std::abs(rows[i] - candidate) == std::abs(i - k)) {
            return false;
        }
    }
    return true;
}

void n_queens_helper (int n, int k, 
        std::vector<std::vector<int>>& res,
        std::vector<int>& rows) {

    if (n == k) {
        //debug(rows);
        res.emplace_back(rows);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (is_feasible(i, k, rows)) {
            rows[k] = i;
            //debug(rows);
            n_queens_helper(n, k+1, res, rows);
            rows[k] = -1;
        }
    }


}

std::vector<std::vector<int>> n_queens (const int n)
{
    std::vector<std::vector<int>> res;
    std::vector<int> rows(n, -1);
    n_queens_helper (n, 0, res, rows);
    return res;
}


int main (void)
{
    auto res = n_queens(8);
    std::cout << res.size() << std::endl;
//    std::cout << res <<std::endl;
    return 0;

}
