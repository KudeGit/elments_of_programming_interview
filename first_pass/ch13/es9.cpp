#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include "../utils.hpp"

std::vector<std::string>
find_smallest_covering_sub_array (const std::vector<std::string> &Q,
        const std::vector<std::string>& A)
{
    std::unordered_set<std::string> isQ(Q.cbegin(), Q.cend());
    std::unordered_map<std::string, int> fQ;

    int min_distance = std::numeric_limits<int>::max();
    int s_res, e_res = 0;

    size_t e = 0, s = 0;
    while (e < A.size()) {
        while (e < A.size() && fQ.size() < isQ.size()) {
            const auto& aE = A[e];
            if (isQ.find(aE) != isQ.end()) {
                auto &f = fQ[aE];
                if(!f) {
                    f = 0;
                }
                ++f;
            }
            ++e;
        }
        while (s < e && fQ.size() == isQ.size()) {
            const auto& aS = A[s];
            if (isQ.find(aS) != isQ.end()) {
                auto& f = fQ[aS];
                --f;
                if (f == 0) {
                    fQ.erase(aS);
                    if(e - s < min_distance) {
                        e_res = e; s_res = s;
                        min_distance = e_res - s_res;
                    }
                }
            }
            ++s;
        }
    }
    return std::vector<std::string>(A.begin() + s_res, A.begin() + e_res);
}



int main (void)
{
    const std::vector<std::string> A = {
        "His", "response", "revealed", "his", 
        "concentration", "on", "preserving", "the", "Union",
        "If", "there", "be", "those", "who", "would", "not",
        "save", "the", "Union", "unless", "they", "could", "at",
        "the", "same", "time", "save"};
    const std::vector<std::string> Q = {"save", "Union"};
    auto res = find_smallest_covering_sub_array(Q, A);
    std::cout << res << std::endl;
    return 0;

}
