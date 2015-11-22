#include <iostream>
#include <vector>
#include "../utils.hpp"
#include <algorithm>

template <class T>
void permutate (std::vector<T>& A, std::vector<int>& P)
{
    for (int i = 0; i < A.size(); ++i) {
        if(P[i] >= 0) {
            int a = i;
            int tmp = A[a];
            do{
                int next_a = P[a];
                P[a] -= P.size();
                int next_tmp = A[next_a];
                A[next_a] = tmp;
                tmp = next_tmp;
                a = next_a;
            }while(a != i);
        }
    }
    for_each (P.begin(), P.end(), [&](int &x){ x += P.size();});
}

int main (void)
{
    std::vector<char> A = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<int> P = {4, 5, 3,  2, 1, 0};
    std::cout << A << std::endl;
    std::cout << P << std::endl;
    permutate(A, P);
    std::cout << A << std::endl;
    return 0;
}
