#include <iostream>
#include <unordered_set>
#include "../utils.hpp"

struct Jug {
    int low, high;
};

std::ostream& operator<< (std::ostream& out, const Jug& j)
{
    out << "(" << j.high << ", " << j.low << ")";
    return out;
}

struct KeyHash {
    size_t operator() (const std::pair<int, int>& A) const {
        return std::hash<int>()(A.first) ^ std::hash<int>()(A.second);
    }
};

struct KeyEqual {
    bool operator() (const std::pair<int, int>& A, const std::pair<int, int>& B) const {
        return A.first == B.first && A.second == B.second;
    }
};

void find_sequence_helper(const std::vector<Jug>& jugs, const int H, const int L, 
        std::vector<Jug>& current, std::vector<Jug>& res,
        std::unordered_set<std::pair<int, int>, KeyHash, KeyEqual>& cache) {

    std::pair<int, int> hl = {H, L};
    if (cache.find(hl) != cache.end()) {
        return;
    }
    if (H < 0 || L < 0 || L > H) {
        return;
    }

    for (const auto& j: jugs) {
        if (L <= j.low && H >= j.high) {
            res = current;
            res.emplace_back(j);
            return;
        } else {
            if(res.empty()) {
                current.emplace_back(j);
                find_sequence_helper(jugs, H - j.high, L - j.low,
                        current, res, cache);
                current.pop_back();
            } else {
                return;
            }
        }
    }
    cache.insert(hl);
}

std::vector<Jug> find_sequence(const std::vector<Jug> jugs,
        const int H, const int L)
{
    std::unordered_set<std::pair<int, int>, KeyHash, KeyEqual> cache;
    std::vector<Jug> current;
    std::vector<Jug> res;
    find_sequence_helper(jugs, H, L, current, res, cache);
    return res;

}


int main (void)
{
    std::vector<Jug> jugs = {
        {230, 240}, {290, 310}, {500, 515}
    };

    auto res = find_sequence(jugs, 2300, 2100);
    int min = 0, max = 0;
    for (const auto& r : res) {
        min += r.low;
        max += r.high;
    }
    std::cout << res << std::endl;
    std::cout <<"min: " << min << std::endl;
    std::cout <<"max: " << max << std::endl;

    return 0;
}
