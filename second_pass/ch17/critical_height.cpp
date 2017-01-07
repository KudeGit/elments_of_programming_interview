#include <iostream>
#include <unordered_map>


struct KeyHash {
    std::size_t operator() (const std::pair<int, int>& P) const {
        return std::hash<int>()(P.first) ^ std::hash<int>()(P.second);
    }
};


struct KeyEqual {
    bool operator() (const std::pair<int, int>& lhs,
                    const std::pair<int, int>& rhs) const {
        return lhs == rhs;
    }
};


int critical_height_helper (const int d, const int c,
        std::unordered_map<std::pair<int,int>, int, KeyHash, KeyEqual>& C)
{
    if (d <= 0 || c <= 0) {
        return 0;
    }
    if (d == 1) {
        return c;
    }
    auto curr_pair = std::make_pair(d,c);
    if (C.find(curr_pair) != C.end()) {
        return C[curr_pair];
    }
    C[curr_pair] = critical_height_helper(d-1, c-1, C) + 1 +
                    critical_height_helper(d-1, c, C);

    return C[curr_pair];

}



int critical_height (const int d, const int c)
{
    std::unordered_map<std::pair<int,int>, int, KeyHash, KeyEqual> C;
    return critical_height_helper(d,c,C);

}


int main (void)
{
    return 0;
}
