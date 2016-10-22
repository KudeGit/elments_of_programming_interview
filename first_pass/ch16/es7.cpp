#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"

void compute_all_matched_parents (int nl, int nr,
        std::vector<std::string>& all_strs,
        std::string current)
{
    if (nl == nr && nl == 0) {
        all_strs.emplace_back(current);
        return;
    }

    if(nl > 0 ) {
        current.push_back('(');
        compute_all_matched_parents(nl - 1, nr,
                all_strs, current);
        current.pop_back();
    }
    if (nr > 0 && nr > nl) {
        current.push_back(')');
        compute_all_matched_parents(nl, nr - 1,
                all_strs, current);
        current.pop_back();
    }
    return;
}


std::vector<std::string> compute_all_matched_parents (int k)
{
    std::vector<std::string> all_strs;
    std::string current;
    compute_all_matched_parents(k, k, all_strs, current);
    return all_strs;
}


int main (void)
{
    auto all_strs = compute_all_matched_parents(3);
    for (const auto& s: all_strs) {
        std::cout << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
