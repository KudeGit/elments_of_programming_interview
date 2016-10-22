#include <iostream>
#include <vector>
#include "../utils.hpp"


template <class T>
void unique (std::vector<T> &A) 
{
    int j = 0;
    for (int i = 1; i< A.size(); ++i) {
        if(A[j] != A[i]) {
            A[++j] = A[i];
        }
    }
    while(A.size() > j+1) {
        A.pop_back();
    }
}


int main (void) 
{
    std::vector<int> A = {1,2,3,4};
    std::vector<int> B = {1,2,2,3,3,3,4,4,4,4,5,6,7,8,9};
    std::vector<int> C = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::vector<int> D = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    unique(A);
    unique(B);
    unique(C);
    unique(D);
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    std::cout << D << std::endl;
    return 0;
}
