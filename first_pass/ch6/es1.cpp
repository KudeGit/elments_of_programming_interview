#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "../utils.hpp"


template <class T>
void dutch_flag (std::vector<T>& A, int idx)
{
    T pivot = A[idx];
    int lower = 0, equal = 0, larger = A.size() - 1;
    while (equal <= larger) {
        if (A[equal] < pivot) {
            std::swap(A[equal++], A[lower++]);
        } else if (A[equal] == pivot) {
            ++equal;
        } else {
            std::swap(A[equal], A[larger--]);
        }
    }
}



int main (void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,5);

    std::vector<int> A = {6,6,4,4,3,3,2,2,1,1};
    std::vector<int> B = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> C = {};


    for (int i = 0; i < 20; ++i) {
        C.push_back(dis(gen));
    }
    int pivot = A[3];
    std::cout << A << std::endl;
    dutch_flag(A, 3);
    std::cout << pivot << ": " <<A << std::endl;
    

    pivot = B[3];
    std::cout << B << std::endl;
    dutch_flag(B, 3);
    std::cout << pivot << ": " <<B << std::endl;

    pivot = C[3];
    std::cout << C << std::endl;
    dutch_flag(C, 3);
    std::cout << pivot << ": " <<C << std::endl;
    
    return 0;


}

