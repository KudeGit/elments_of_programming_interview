#include <iostream>
#include <vector>
#include "ch14.hpp"

int main (void)
{
    std::vector<int> A{3,7,8,1,3,8,1,7,5,1};
    sort_by_key(A);
    for (auto a: A) {
        std::cout << a << std::endl;
    }
    return 0;

}
