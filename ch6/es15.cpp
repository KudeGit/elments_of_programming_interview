#include <vector>
#include <algorithm>
#include "../utils.hpp"

void rotate (std::vector<int>& A, const int k)
{
    std::reverse(A.begin(), A.end());
    std::reverse(A.begin(), A.begin() + k);
    std::reverse(A.begin() + k, A.end());
}


int main (void) 
{
    std::vector<int> A = {0,1,2,3,4,5};
    std::cout << A << std::endl;
    rotate(A, 1);
    std::cout << A << std::endl;
    return 0;
}
