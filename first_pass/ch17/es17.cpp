#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"

bool is_interleaving_helper (const std::string& str, 
        const std::string& A, const std::string& B,
        int a, int b, int c, std::vector<std::vector<int>>& K)
{
    if (c == -1) {
        return true;
    }
    bool is_match = false;
    if (a >= 0) {
        is_match |= str[c] == A[a];
    }
    if (b >= 0) {
        is_match |= str[c] == B[b];
    }
    if (!is_match) {
        return false;
    }
    if (K[a+1][b+1] != -1) {
        return K[a+1][b+1] == 1;
    }
    bool res = false;
    if (a >= 0 && str[c] == A[a]) {
        res |= is_interleaving_helper(str, A, B, a - 1, b, c - 1, K);
    }
    if (!res && b >= 0 && str[c] == B[b]) {
        res |= is_interleaving_helper(str, A, B, a, b - 1, c - 1, K);
    }
    K[a+1][b+1] = res ? 1 : 0;
    return res;

}
bool is_interleaving (const std::string& A, const std::string& B, 
        const std::string& str)
{
    if (A.size() + B.size() != str.size()) {
        return false;
    }
    std::vector<std::vector<int>> K(A.size() + 1, std::vector<int>(B.size() + 1, -1));
    return is_interleaving_helper (str, A, B, A.size() - 1,
            B.size() - 1, str.size() - 1, K) == 1;
}

int main (void)
{
    std::string s1("gtaa");
    std::string s2("atc");
    std::string t1("gtataac");
    std::string t2("gattaca");
    std::string t3("gatacta");
    auto res1 = is_interleaving(s1,s2,t1);
    debug(res1);
    auto res2 = is_interleaving(s1,s2,t2);
    debug(res2);
    auto res3 = is_interleaving(s1,s2,t3);
    debug(res3);
    return 0;

}
