#include <iostream>
#include <vector>
#include <functional>
#include "../utils.hpp"

template <class T, class F>
void remove_if(std::vector<T>& A, F predicate)
{
    int j = 0;
    for (int i = 0; i < A.size(); ++i) {
        if(!predicate(A[i])) {
            A[j++] = A[i];
        }
    }
    for (; j< A.size(); ++j) {
        A[j] = 0;
    }
}


int main(void)
{
    std::vector<int> A = {5,3,7,11,2,3,15,5,7};
    remove_if(A, [](int x)->bool {return x == 3;});
    std::cout << A << std::endl;
    return 0;
}
