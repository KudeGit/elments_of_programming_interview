#include <iostream>
#include <vector>
#include "../utils.hpp"



template <class T>
std::vector<std::vector<T>> compute_all_power_sets_iteratively (
        const std::vector<T>& A)
{
    std::vector<std::vector<T>> all_sets;
    for (int i = 0; i  < (1 << A.size()); ++i) {
        int x = i;
        std::vector<T> current;
        int pos = 0;
        while (x) {
            if (x & 0x01) {
                current.emplace_back(A[pos]);
            }
            x >>= 1;
            pos++;
        }
        all_sets.emplace_back(current);
    }
    return all_sets;
}



template <class T> 
std::vector<std::vector<T>> compute_all_sets (
        int k, const std::vector<T>& A)
{
    if (k == A.size()) {
        return std::vector<std::vector<T>>(1, std::vector<T>());
    }
    auto res = compute_all_sets(k+1, A);
    std::vector<std::vector<T>> new_res(res);
    for (auto& r: res) {
        r.push_back(A[k]);
        new_res.emplace_back(r);
    }
    return new_res;
}


int main (void) 
{
    std::vector<int> A = {1,2,3};
    auto res_iter = compute_all_power_sets_iteratively(A);
    for (const auto& r: res_iter) {
        std::cout << "r: "  << r << std::endl;
    }
    banner();

    auto res_rec = compute_all_sets(0, A);
    for (const auto& r: res_rec) {
        std::cout << "r: "  << r << std::endl;
    }

    return 0;
}
