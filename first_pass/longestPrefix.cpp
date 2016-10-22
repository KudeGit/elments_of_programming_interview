#include <iostream>
#include <string>
#include <vector>
#include "../utils.hpp"


using namespace std;


//#define debug(x) cout << #x ": " << endl;
bool check_prefix (const std::vector<string>& A, const string curr)
{
    for (int i = 1; i < A[i].size(); ++i) {
        for (int j = 0; j < curr.size(); ++j) {
            if (curr[j] != A[i][j]) {
                return false;
            }
        }
    }
    return true;
}

string longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long int max_len = 0;
    for (int i = 1; i <= A[0].size(); ++i) {
        debug(A[0]);
        auto curr_prefix = A[0].substr(0, i);
        debug(curr_prefix);
        if (check_prefix(A, curr_prefix) == true) {
            max_len = i;
            debug(max_len);
        } else {
            break;
        }
    }
    return A[0].substr(0, max_len);
    
}

int main (void)
{
    std::vector<std::string> strs = {"abcd", "abde", "abcf"};
    auto res  = longestCommonPrefix(strs);
    cout << res << endl;
    return 0;

}
