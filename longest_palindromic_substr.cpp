#include <iostream>
#include <string>
#include "utils.hpp"

using namespace std;


string longestPalindrome(const string& A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    std::vector<std::vector<bool>> K(A.size(), std::vector<bool>(A.size(), false));
    int max_len = 1;
    int max_start = 0;

    for (int i = 0; i < A.size(); ++i) {
        K[i][i] = true;
    }
    for (int i = 1; i < A.size(); ++i) {
        if (A[i] == A[i-1]) {
            if (max_len < 2) {
                max_len = 2;
                max_start = i-1;
            }
            K[i-1][i] = true;
        }
    }
    debug(K);

    for (int k = 3; k <= A.size(); ++k) {
        debug(k);
        for (int i = k - 1; i < A.size(); ++i) {
            int j = i - k + 1;
            if (A[j] == A[i] && K[j+1][i-1] == true) {
                K[j][i] = true;
                if (max_len < k) {
                    max_len = k;
                    max_start = j;
                }
            }
        }
    }
    debug(K);
    debug(max_len);
    debug(max_start);
    return A.substr(max_start, max_len);
}

int main(void)
{
    auto res = longestPalindrome("sgdannasaieed");
    debug(res);
    return 0;
}
