#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "utils.hpp"

using namespace std;




class Solution {
    public:
        bool check_valid_position (const int candidate_col, const int curr_row, const vector<int>& cols) {
            for (int i = 0; i < cols.size(); ++i) {
                if(cols[i] == candidate_col) {
                    return false;
                }
                if (std::abs(cols[i] - candidate_col) == std::abs(i - curr_row)) {
                    return false;
                }
            }
            return true;
        }

        void solveNQueens(int n, int curr_row, vector<int>& cols, vector<vector<string>>& res) {
            if (n == cols.size()) {
                auto curr_res = vector<string>(n, string(n, '.'));
                for (int i = 0; i < n; ++i) {
                    curr_res[i][cols[i]]='Q';
                }
                res.emplace_back(curr_res);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (check_valid_position(i, curr_row, cols)) {
                    cols.emplace_back(i);
                    solveNQueens(n, curr_row+1, cols, res);
                    cols.pop_back();
                }
            }
        }


        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> res;
            vector<int> cols;
            int curr_row = 0;
            solveNQueens(n, curr_row, cols, res);
            return res;
        }
};


int main (void)
{
    Solution s;
    auto res = s.solveNQueens(4);
    return 0;
}
