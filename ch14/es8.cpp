#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include "../utils.hpp"


struct Interval {
    int left;
    int right;
};
std::ostream& operator<< (std::ostream& out, const Interval& I)
{
    out << "(" << I.left  << ", " << I.right << ")";
    return out;
}

struct CompareLeft
{
    bool operator() (const Interval* a, const Interval* b) const {
        return a->left != b->left ?
            a->left < b->left :
            a->right < b->right;
    }
};


struct CompareRight
{
    bool operator() (const Interval* a, const Interval* b) const {
        return a->right != b->right ?
            a->right < b->right :
            a->left < b->left;
    }
};

std::vector<int> find_smallest_covering_set (
        const std::vector<Interval> intervals)
{
    std::vector<int> result;
    std::set<const Interval*, CompareLeft> L;
    std::set<const Interval*, CompareRight> R;

    for (const auto& i: intervals) {
        L.emplace(&i); R.emplace(&i);
    }
    while (!R.empty()) {
        auto b = (*R.cbegin())->right;
        auto l = L.cbegin();
        result.emplace_back(b);
        while (l != L.cend() && (*l)->left <= b) {
            R.erase(*l);
            L.erase(l);
            l = L.cbegin();
        }
    }
    return result;
}


int main (void)
{
    std::vector<Interval> intervals = {
        Interval{0,2}, Interval{1,4}, Interval{3,5}};
    auto res = find_smallest_covering_set(intervals);
    std::cout << res << std::endl;

    return 0;
}
