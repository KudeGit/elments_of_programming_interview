#include <iostream>
#include <limits>
#include <cassert>
#include <vector>
#include "../utils.hpp"
using namespace std;

double find_median2 (const vector<int> &A,
        int s_a, int len_a,
        const vector<int> &B,
        int s_b, int len_b,
        int k)
{
    if (k == 0) {
        return std::min(A[s_a], B[s_b]);
    }
    int i, j;
    //if (len_a > len_b) {
        i = static_cast<double>(len_a)/
            static_cast<double>(len_a + len_b) * (k - 1);
        j = k - i - 1;
    //} else {
    //    j = static_cast<double>(len_b)/
    //        static_cast<double>(len_a + len_b) * (k - 1);
    //    i = k - j - 1;
    //}
    //debug(i);
    //debug(j);

    int A_i_1 = i > 0 ? A[s_a + i - 1] : std::numeric_limits<int>::min();
    int A_i = i < len_a ? A[s_a + i] : std::numeric_limits<int>::max();
    int B_j_1 = j > 0 ? B[s_b + j - 1] : std::numeric_limits<int>::min();
    int B_j = j < len_b ? B[s_b + j] : std::numeric_limits<int>::max();
    //debug(s_a);
    //debug(s_b);
    //debug(len_a);
    //debug(len_b);
    if (A_i_1 < B_j && B_j < A_i) {
        return B_j;
    } else if (B_j_1 < A_i && A_i < B_j) {
        return A_i;
    } else if (A_i < B_j) {
       // std::vector<int> AA(A.begin() + i + 1, A.end());
       // std::vector<int> AAA(A.begin() + s_a + i + 1,
       //         A.begin() + s_a + i + 1 + len_a - i - 1);
       // //debug(AA);
       // //debug(AAA);

       // std::vector<int> BB(B.begin(), B.begin() + j + 1);
       // std::vector<int> BBB (B.begin() + s_b, B.begin() + s_b + j + 1);
       // //debug(BB);
       // //debug(BBB);

        return find_median2(A, s_a + i + 1, len_a - i - 1,
                B, s_b, j + 1,
                k - i - 1);
    } else {
       // std::vector<int> AA(A.begin(), A.begin() + i + 1);
       // std::vector<int> AAA(A.begin() + s_a, A.begin() + s_a + i + 1);
       // //debug(AA);
       // //debug(AAA);
       // std::vector<int> BB(B.begin() + j + 1, B.end());
       // std::vector<int> BBB(B.begin() + s_b + j + 1, 
       //         B.begin() + s_b + j + 1 + len_b - j - 1);
       // //debug(BB);
       // //debug(BBB);
        return find_median2(A, s_a, i + 1,
                B, s_b + j + 1, len_b - j - 1, k - j - 1);
    }
}

double find_median (const vector<int> &A,
            const vector<int> &B, int k)
{
    int i = static_cast<double>(A.size())/
        static_cast<double>(A.size() + B.size()) * (k - 1);
    int j = k - i - 1;
    //debug(i);
    //debug(j);
    int A_i_1 = i > 0 ? A[i - 1] : std::numeric_limits<int>::min();
    int A_i = i < A.size() ? A[i] : std::numeric_limits<int>::max();
    int B_j_1 = j > 0 ? B[j - 1] : std::numeric_limits<int>::min();
    int B_j = j < B.size() ? B[j] : std::numeric_limits<int>::max();
    //debug(A_i_1);
    //debug(A_i);
    //debug(B_j_1);
    //debug(B_j);
    //return 0.0;
    if (A_i_1 < B_j && B_j < A_i) {
        return B_j;
    } else if (B_j_1 < A_i && A_i < B_j) {
        return A_i;
    } else if (A_i < B_j) {
        std::vector<int> AA(A.begin() + i + 1, A.end());
        std::vector<int> BB(B.begin(), B.begin() + j + 1);
        //debug(AA);
        //debug(BB);
        return find_median(AA, BB, k - i - 1);
    } else {
        std::vector<int> AA(A.begin(), A.begin() + i + 1);
        std::vector<int> BB(B.begin() + j + 1, B.end());
        //debug(AA);
        //debug(BB);
        return find_median(AA, BB, k - j - 1);
    }
}


int find_kth_elem_in_two_sorted_array (const int *A, int N, 
        const int* B, int M, int K)
{
    //assert(A);
    //assert(B);
    //assert(N >= 0);
    //assert(M >= 0);
    //assert(K <= M + N);
    //assert(K > 0);

    int i = static_cast<int> (
        static_cast<double>(N)/static_cast<double>(M+N) * (K - 1));
    int j = K - 1 - i;

    int A_i_1 = i > 0 ? A[i-1] : std::numeric_limits<int>::min();
    int A_i = i >= N ? std::numeric_limits<int>::max() : A[i];
    int B_j_1 = j > 0 ? B[j-1] : std::numeric_limits<int>::min();
    int B_j = j >= M ? std::numeric_limits<int>::max() : B[j];

    if (A_i_1 < B_j && B_j < A_i) {
        return B_j;
    } else if (B_j_1 < A_i && A_i < B_j) {
        return A_i;
    } else {
        if (A_i < B_j) {
            return find_kth_elem_in_two_sorted_array(A + i + 1,
                    N - i - 1, B, j, K - i - 1);
        } else {
            return find_kth_elem_in_two_sorted_array(A,
                    i, B + j + 1, M - j - 1, K - j - 1);
        }
    }
    return 0;
}



int main (void)
{
    int A[] = {-50, -41, -40, -19, 5, 21,28};
    int B[] = {-50, -21, -10};
    int N = sizeof(A)/sizeof(int);
    int M = sizeof(B)/sizeof(int);

    std::vector<int> AA = {35};//{-50, -41, -40, -19, 5, 21, 28 };
    std::vector<int> BB = {1, 26, 35, 49 };

    for (int i = 1; i <= AA.size() + BB.size(); ++i) {
        auto res2 = find_median2(AA, 0, AA.size(),
                BB, 0, BB.size(), i);
        debug(res2);

        auto res3 = find_median(AA,BB,i);
        debug(res3);
    }

    int k1 = (AA.size() + BB.size())/2 + 1;
    int k2 = (AA.size() + BB.size())/2;
    debug(k1);
    debug(k2);
    auto res1 = find_median2(AA,0, AA.size(),
            BB, 0, BB.size(), k1);
    auto res2 = find_median2(AA,0, AA.size(),
            BB, 0, BB.size(), k2);
    debug(res1);
    debug(res2);
    return 0;

    return 0;
    banner();
    
    return 0;
}
