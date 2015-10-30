#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "../utils.hpp"


void dutch_flag (std::vector<int>& A, int k)
{
    int pivot = A[k];
    int low = 0, equal = 0, larger = A.size() - 1;
    while (equal <= larger) {
        if(A[equal] < pivot) {
            std::swap(A[equal++], A[low++]);
        } else if (A[equal] == pivot) {
            ++equal;
        } else {
            std::swap(A[equal], A[larger--]);
        }
    }
}

template <class T>
void three_keys(std::vector<char>& A, const std::vector<T>& keys)
{
    if(keys.size() != 3) {
        return;
    }
    int key1 = 0, key2 =0, key3 = A.size() - 1;
    while (key2 <= key3) {
        if(A[key2] == keys[0]) {
            std::swap(A[key1++], A[key2++]);
        } else if(A[key2] == keys[1]) {
            ++key2;
        } else if (A[key2] == keys[2]) {
            std::swap(A[key2], A[key3--]);
        } else {
            std::cout << "more than 3 keys... aborting grouping" << std::endl;
            return;
        }
    }
}

int main (void)
{

    std::default_random_engine g(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> d(1,6);
    std::vector<int> A;
    for (int i = 0; i< 15; ++i) {
        A.push_back(d(g));
    }
    std::cout << A << std::endl;
    int k = 10;
    std::cout << "pivot: " << A[k] << std::endl;
    dutch_flag(A, k);
    std::cout << A << std::endl;


    std::vector<char> B = {'a','b','c','a','c','b','b','a','c'};
    std::cout << B << std::endl;
    std::vector<char> keys = {'a', 'b', 'c'};
    three_keys(B, keys);
    std::cout << B << std::endl;


    return  0;
}

