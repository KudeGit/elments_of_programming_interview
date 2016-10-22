#include <iostream>
#include <vector>
#include <functional>
#include "../utils.hpp"

template <class T, class F>
void remove_if(std::vector<T> &A, F predicate)
{
    int k= 0;
    for (int i = 0; i < A.size(); ++i) {
        if(predicate(A[i]) != true) {
            A[k++] = A[i];
        }
    }
    while(A.size() > k) {
        A.pop_back();
    }
}

int main(void)
{
    std::vector<int> A1 = {1,2, 3, 3, 4, 5, 6, 7};
    std::vector<int> A2 = {3, 3, 3, 3, 3, 3, 3, 3};
    std::vector<int> A3 = {1,2,2,2,2,2,2,2,2,3,3,3,3,3};
    auto predicate = [] (int x) -> bool {return x == 3;};

    std::cout << A1 << std::endl;
    remove_if(A1, predicate);
    std::cout << A1 << std::endl;

    std::cout << A2 << std::endl;
    remove_if(A2, predicate);
    std::cout << A2 << std::endl;

    std::cout << A3 << std::endl;
    remove_if(A3, predicate);
    std::cout << A3 << std::endl;

    return 0;
}
