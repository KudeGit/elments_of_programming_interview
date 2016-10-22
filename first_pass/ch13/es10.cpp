#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cassert>
#include "../utils.hpp"

std::vector<std::string>
find_ordered_digest (const std::vector<std::string> &Q,
        const std::vector<std::string>& A)
{
    std::unordered_map<std::string, int> K;
    std::vector<int> L(Q.size(), -1);
    std::vector<int> D(Q.size(), -1);
    int s_res = -1;
    int e_res = -1;
    int min_distance = std::numeric_limits<int>::max();

    for (int i = 0; i < Q.size(); ++i) {
        K[Q[i]] = i;
    }
    debug(K);
    for (int i = 0; i < A.size(); ++i) {
        if (K.find(A[i]) != K.end()) {
            const auto& k = K[A[i]];
            debug(k);
            L[k] = i;
            if (k == 0) {
                D[k] = 1;
            } else if (D[k-1] != -1) {
                D[k] = i - (L[k-1] - D[k-1]) - 1;
            }
            if (k == Q.size() - 1) {
                if (D[k] != -1 && D[k] < min_distance) {
                    debug(i);
                    debug(D[k]);
                    min_distance = D[k];
                    s_res = i - D[k];
                    e_res = i;
                    debug(s_res);
                    debug(e_res);
                }
            }
        }
    }
    assert(s_res != -1 && e_res != -1);
    return std::vector<std::string>(A.begin() + s_res, A.begin() + e_res + 1);
}



int main (void)
{
    const std::vector<std::string> A = {
        "His", "response", "revealed", "his", 
        "concentration", "on", "preserving", "the", "Union",
        "If", "there", "be", "those", "who", "would", "not",
        "save", "the", "Union", "unless", "they", "could", "at",
        "the", "same", "time", "save"};
    const std::vector<std::string> Q = {"Union", "save"};
    auto res = find_ordered_digest(Q, A);
    std::cout << res << std::endl;
    return 0;

}
