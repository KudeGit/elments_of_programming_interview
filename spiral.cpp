#include <iostream>
#include <vector>
#include "../utils.hpp"

using namespace std;

std::vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    int K = std::min(A.size(), A[0].size())/2;
    debug(K);
    int M = A.size();
    int N = A[0].size();
    for (int k = 0; k < K; ++k) {
        for (int i = k; i < N - k; ++i) {
            result.push_back(A[k][i]);
        }
        debug(result);
        for (int i = k + 1; i < M - k; ++i) {
            result.push_back(A[i][N - k - 1]);
        }
        debug(result);
        for (int i = N - k - 2; i >= k; --i) {
            result.push_back(A[M - k - 1][i]);
        }
        debug(result);
        for (int i = M - k - 2; i > k; --i) {
            result.push_back(A[i][k]);
        }
        debug(result);
    }
    
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

}

int main (void)
{
//    vector<vector<int>> A =  {{313, 157, 290, 113, 119, 118, 187, 360, 104, 365, 197, 103, 355, 240, 337, 174, 138, 252}};
//    vector<vector<int>> A = {{11, 217, 223, 213, 178, 226, 166, 212, 121, 277, 188, 5, 56, 354, 6},
//        {69, 384, 201, 369, 72, 174, 320, 265, 61, 397, 152, 10, 385, 288, 23}};
    vector<vector<int>> A = {
        { 1,  2,  3 },
        { 4,  5,  6 },
        { 7,  8,  9 },
        { 10,  12,  13 },
        { 14,  15,  16 },
    
    };
//    vector<vector<int>> A = {
//        {1, 2, 3},
//        {4, 5, 6}};
    for(const auto& a: A) {
        cout << a << endl;
    }
    auto res = spiralOrder(A);
    cout << res << endl;
    return 0;
}
