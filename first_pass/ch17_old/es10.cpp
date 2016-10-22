#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>







//return difference between split
int compute_fair_split (const std::vector<int>& A)
{
    long tot = std::accumulate(A.begin(), A.end(), 0);
    std::unordered_set<int> is_Ok;
    is_Ok.insert(0);
    for (const auto& a: A) {
        for (int v = tot >> 1; v > 0; --v) {
            if (is_Ok.find(v - a) != is_Ok.end()) {
                is_Ok.insert(v);
            }
        }
    }

    for (int v = tot >> 1; v > 0; --v) {
        if (is_Ok.find(v) != is_Ok.end()) {
            return (tot - v)-v;
        }
    }
    return tot;
}




//explixit approach


int compute_fair_split2 (const std::vector<int>& A)
{
    long tot = std::accumulate(A.begin(), A.end(), 0);
    std::vector<std::vector<bool>> table((tot >> 1) + 1, std::vector<bool>(A.size()+1, false));
    //base case 0; empty set
    for (int i = 0; i <= A.size(); ++i) {
        table[0][i] = true;
    }
    for (int v = 1; v <= (tot >> 1); ++v) {
        for (int i = 0; i < A.size(); ++i) {
            table[v][i+1] = table[v][i] || (A[i] <= v ? table[v - A[i]][i] : false);
        }
    }
    
    for (int v = (tot >> 1); v > 0; --v) {
        if (table[v].back()) {
            return tot - v - v;
        }
    }
    return tot;

}


int main (void)
{
    std::vector<int> A = {1,2,3,4,5};
    auto res1 = compute_fair_split(A);
    auto res2 = compute_fair_split2(A);
    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    return 0;
}
