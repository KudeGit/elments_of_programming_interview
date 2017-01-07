#include <iostream>
#include <vector>
#include <algorithm>


void rotate (std::vector<int>& A, int k)
{
    k %= A.size();
    std::reverse(A.begin(), A.end());
    std::reverse(A.begin(), A.begin() + k);
    std::reverse(A.begin()+k, A.end());
}


int main (void)
{
    return 0;
}

