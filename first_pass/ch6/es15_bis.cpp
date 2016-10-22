#include <iostream>
#include <vector>
#include "../utils.hpp"

template<class T>
void rotate(std::vector<T>& A, int k)
{
    std::reverse(A.begin(), A.end());
    std::reverse(A.begin(), A.begin() + k);
    std::reverse(A.begin() + k, A.end());
}



int main (void)
{
    std::vector<int> A = {0,1,2,3,4,5,6};
    std::cout << A << std::endl;
    rotate(A, 2);
    std::cout << A << std::endl;

    return 0;
}

