#include <iostream>
#include <unordered_set>
#include <utility>
#include "../../utils.hpp"

using Jug = std::pair<int, int>;

bool is_feasible (const std::vector<Jug>& jugs, const int L, const int H)
{
    if (L > H || (L < 0 && H < 0)) {
        return false;
    }

    for (auto& j: jugs) {
        if ((L <= j.first && H <= j.second) ||  //this is wrong...
                                                //take an simple example {7,12} single jug{3,5}
                is_feasible(jugs, L - j.first, H - j.second)) {
            return true;
        }
    }
    return false;
}


struct HashKey {
    size_t operator() (const std::pair<int, int>& a) const {
        return std::hash<int>()(a.first) ^
            std::hash<int>()(a.second);
    }
};

bool is_feasible_helper (const std::vector<Jug>& jugs,
        const std::pair<int, int> curr_range,
        const std::pair<int, int> max_range,
        std::unordered_set<std::pair<int, int>, HashKey>& C)
{
    if (curr_range.first >= max_range.first &&
            curr_range.first <= max_range.second &&
            curr_range.second >= max_range.first &&
            curr_range.second <= max_range.second) {
        return true;
    }
    if (curr_range.first > max_range.second  || C.find(curr_range) != C.end()) {
        return false;
    }

    for (auto& j: jugs) {
        if (is_feasible_helper(jugs,
                    {curr_range.first + j.first, curr_range. second + j.second},
                    max_range, C)) {
            return true;
        }
    }
    C.insert(curr_range);
    return false;
}
bool is_feasible (const std::vector<Jug> jugs,
        const std::pair<int, int> max_range) {
    std::unordered_set<std::pair<int,int>, HashKey> C;
    return is_feasible_helper (jugs, {0,0}, max_range, C);

}


int main (void)
{
    std::vector<Jug> jugs{{230, 240}, {290,310}, {500,515}};
    auto res = is_feasible(jugs, {2100, 2300});
    debug(res);
    return 0;
}

