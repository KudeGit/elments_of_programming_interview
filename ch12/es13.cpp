#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <cassert>
#include "../utils.hpp"



int find_k_th_element (std::istringstream& sin, int k)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> Q;
    int x;
    while (sin >> x) {
        if (Q.size() < k) {
            Q.push(x);
        } else {
            if (x < Q.top()) {
                Q.pop();
                Q.push(x);
            }
        }
    }
    return Q.top();
}

int find_k_th__largest_element (std::istringstream& sin, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
    int x;
    while (sin >> x) {
        if (Q.size() < k) {
            Q.push(x);
        } else {
            if (x > Q.top()) {
                Q.pop();
                Q.push(x);
            }
        }
    }
    return Q.top();
}


template <class T, class F>
int partition (std::vector<T>& A, int l, int r, F f)
{
    if(!(l >= 0 && r < A.size())){
        debug(l);
        debug(r);
    }
    auto pivot = A[l];
    int j = l + 1;
    for (int i = l + 1; i <= r; ++i) {
        if (f(A[i],pivot)) {
            std::swap(A[i], A[j++]);
        }
    }
    std::swap(A[--j], A[l]);
    return j;
}

template<class T, class F>
void qsort(std::vector<T>& A, int l, int r, F f)
{
    if (l >= r) {
        return;
    }
    auto pivot = partition(A, l, r, f);
    qsort(A, l, pivot - 1, f);
    qsort(A, pivot + 1, r, f);
}


template <class T, class F>
void qsort (std::vector<T>& A, F f)
{
    qsort(A, 0, A.size() - 1, f);
}



void qsort(std::vector<int>& A)
{
    qsort<int>(A, std::less<int>());
}



template <class F>
int find_kth_element_helper (std::vector<int>& A, const int l, const int r, int k, F f)
{
    if (l >= r) {
        return l;
    }
    int pivot = partition(A, l, r, f);

    //debug(l);
    //debug(r);
    //debug(k);
    //debug(pivot);
    
    if (pivot == k) {
        return k;
    } else if (pivot < k) {
        return find_kth_element_helper(A, pivot + 1, r, k, f);
    } else {
        return find_kth_element_helper(A, l, pivot - 1, k, f);
    }
}


template <class F>
int find_kth_element (std::vector<int>& A, int k)
{
    if (k < 0 || k >= A.size()) {
        return -1;
    }
    return find_kth_element_helper(A, 0, A.size() - 1, k, F());
}



int find_k_th__largest_element_2 (std::istringstream& iss, int k)
{
    int x;
    std::vector<int> A;
    while (iss >> x) {
        A.emplace_back(x);
        if(A.size() >= (k << 1) - 1) {
            auto res = find_kth_element<std::greater<int>>(A, k);
            A.resize(k);
        }
    }
    auto  res = find_kth_element<std::greater<int>>(A, k-1);
    return A[res];
}

int main (void)
{
    std::string str("1 2 3 4 5 6 7 8 9 10");
    for (int i = 0; i < 10; ++i) {
        std::istringstream iss(str);
        auto res1 = find_k_th__largest_element(iss, i+1);
        std::cout << res1 << std::endl;
    }

    for (int i = 0; i < 10; ++i) {
        std::istringstream iss(str);
        auto res2 = find_k_th__largest_element_2(iss, i+1);
        std::cout << res2 << std::endl;
    }
    

    std::vector<int> A = {1,2,3,4,5,6,7,8,9};
    qsort(A);
    std::cout << A << std::endl;

    std::reverse(A.begin(), A.end());
    qsort(A);
    std::cout << A << std::endl;

    std::random_shuffle(A.begin(), A.end());
    qsort(A);
    std::cout << A << std::endl;




    std::reverse(A.begin(), A.end());
    qsort(A, std::greater<int>());
    std::cout << A << std::endl;

    std::random_shuffle(A.begin(), A.end());
    qsort(A, std::greater<int>());
    std::cout << A << std::endl;


    for (int i = 0; i < A.size(); ++i) {
        std::random_shuffle(A.begin(), A.end());
        auto k = find_kth_element<std::greater<int>>(A, i);
        std::cout << i << " kth element is: " << A[k] << std::endl;
    }

    banner();
    for (int i = 0; i < A.size(); ++i) {
        std::random_shuffle(A.begin(), A.end());
        auto k = find_kth_element<std::greater<int>>(A, A.size() - 1 - i);
        std::cout << i << " kth element is: " << A[k] << std::endl;
    }
    banner();

    for (int i = 0; i < A.size(); ++i) {
        std::random_shuffle(A.begin(), A.end());
        auto k = find_kth_element<std::less<int>>(A, A.size() - i - 1);
        std::cout << A.size() - 1 - i << " kth element is: " << A[k] << std::endl;
    }


    return 0;
}
