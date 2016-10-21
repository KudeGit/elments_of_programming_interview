#include <iostream>
#include <stack>
#include <vector>


int find_max_area (const std::vector<int>& H)
{
    int max_area = 0;
    std::stack<int> S;
    for (int i = 0; i < H.size(); ++i) {
        while (!S.empty() && H[i] <= H[S.top()]) {
            int h = H[S.top()];
            S.pop();
            int b = S.empty() ? i : i - S.top() - 1;
            max_area = std::max (max_area, b * h);
        }
        S.push(i);
    }
    while (!S.empty()) {
        int h = H[S.top()];
        int b = S.empty() ? H.size() : H.size() - S.top() - 1;
        max_area = std::max (max_area, b * h);
    }
    return max_area;
}


//it can be used to solve the maximal area rectangle problem
//building an histogram row by row. 
int maximalRectangle (std::vector<std::vector<char>>& matrix)
{
    std::vector<std::vector<int>> S(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    if (matrix.empty()) {
        return 0;
    }
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
          S[i][j] = matrix[i][j] - '0';
        }
    }
    int max_area = 0;
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if(i > 0 && S[i][j] == 1) {
                S[i][j] = S[i-1][j] + 1;
            }
        }
        max_area = std::max(find_max_area(S[i]), max_area);
    }
    return max_area;
}




//tested on leetcode: https://leetcode.com/problems/largest-rectangle-in-histogram/
int main (void)
{
    return 0;
}
