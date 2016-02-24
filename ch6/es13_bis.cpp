#include <iostream>
#include <vector>
#include "../utils.hpp"

template <class T>
void permutate (std::vector<T> &A, std::vector<int> &P)
{
    if (A.size() != P.size()) {
        return;
    }

    for (int i = 0; i < A.size(); ++i) {
        if(P[i] > 0) {
            int idx_a = i;
            T a = A[idx_a];
            do {
                int next_idx_a = P[idx_a];
                T next_a = A[next_idx_a];
                A[next_idx_a] = a;
                P[idx_a] -= P.size();

                a = next_a;
                idx_a = next_idx_a;
            } while (idx_a != i);
        }
    }
    for_each(P.begin(), P.end(), [&](int &x) { x += P.size();});
}


int main (void)
{
    std::vector<int> P = {2,0,1,3};
    std::vector<char> A = {'a', 'b', 'c', 'd'};
    permutate(A,P);
    std::cout << A << std::endl;
    return 0;
}
