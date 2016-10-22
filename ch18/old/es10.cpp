#include <iostream>
#include <vector>
#include <tuple>
#include "../utils.hpp"

std::tuple<int, int> is_2_sum (const std::vector<int>& A, const int K)
{
    int i = 0, j = A.size() - 1;
    while (i < j) {
        //debug(i); debug(j);
        if (A[i] + A[j] == K) {
            return std::make_tuple(i,j);
        } else {
            if (A[i] + A[j] < K) {
                ++i;
            } else {
                --j;
            }
        }
    }
    return std::make_tuple(-1, -1);
}



std::tuple<int, int> is_2_sum_abs_sorted (const std::vector<int>& A, int K)
{
    int i = 0, j = A.size() - 1;
    while (i < j) {
        if (A[i]+A[j] == K) {
            return std::make_tuple(i,j);
        } else {
            if (A[i] + A[j] < K) {
                if (A[i] < A[j]) {
                    ++i;
                } else {
                    --j;
                }
            } else {
                if (A[i] > A[j]) {
                    ++i;
                } else {
                    --j;
                }
            }
        }
    }
    return std::make_tuple(-1, -1);

}
template <class Comp>
std::tuple<int, int> pair_sum_with_comp (const std::vector<int>& A, const int K, Comp comp)
{
    int i = 0, j = A.size() - 1;
    //find first positive or first negative
    while (i < A.size() && comp(A[i], 0)) {
        ++i;
    }
    //find last positive or negative
    while (j >= 0 && comp(A[j], 0)) {
        --j;
    }
    while (i < j) {
        if (A[i] + A[j] == K) {
            return std::make_tuple(i,j);
        } else {
            if (std::abs(A[i] + A[j]) < std::abs(K)) {
                do{
                    ++i;
                } while(i < A.size() && comp(A[i], 0));
            } else {
                do {
                    --j;
                } while(j >= 0 && comp(A[j], 0));
            }
        }
    }
    return std::make_tuple(-1, -1);
}


std::tuple<int, int> pair_sum_pos_neg (const std::vector<int>& A, const int K)
{
    int i = A.size() - 1; //positives entry
    int j = A.size() - 1; //nevagitve entry

    while (i >= 0 && A[i] < 0) {
        --i;
    }
    while (j >= 0 && A[j] >= 0) {
        --j;
    }
    while (i >= 0 && j >= 0) {
        if (A[i] + A[j] == K) {
            return std::make_tuple(i,j);
        } else {
            if (A[i] + A[j] < K) {
                do {
                    --j;
                } while (j >= 0  && A[j] >= 0);
            } else  {
                do {
                    --i;
                } while (i >= 0 && A[i] < 0);
            }
        }
    }
    return std::make_tuple(-1, -1);
}


std::tuple<int, int> pair_sum (const std::vector<int>& A, const int K)
{
    auto res = pair_sum_with_comp(A, K, [](const int a, const int b) {return a < b;});
    if (std::get<0>(res) != -1 && std::get<1>(res) != -1) {
        return res;
    }
    res = pair_sum_with_comp(A, K, [](const int a, const int b) {return a >= b;});
    if (std::get<0>(res) != -1 && std::get<1>(res) != -1) {
        return res;
    }
    return pair_sum_pos_neg(A, K);
}

int main (void)
{
    std::vector<int> a_abs_sorted = {-49, 75, 103, -147, 164, -197, -238, 314, 348, -422};
    std::cout << a_abs_sorted << std::endl;


    auto res = pair_sum(a_abs_sorted, 75+164);
    std::cout << res << std::endl;

    res = pair_sum(a_abs_sorted, -147-197);
    std::cout << res << std::endl;



    res = pair_sum(a_abs_sorted, 167);
    std::cout << res << std::endl;


    return 0;

}
