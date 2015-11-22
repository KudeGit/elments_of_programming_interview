#include <iostream>
#include <random>
#include "../utils.hpp"

template <std::size_t N>
int findCelebritySlow(bool (&A)[N][N])
{
    int knows[N] = {0};
    for(int i =0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j]) {
                knows[j]++;
            }
        }
    }
    int celebrity = 0;
    for(int i = 1; i < N; i++) {
        if(knows[i] > knows[celebrity]) {
            celebrity = i;
        }
    }
    return celebrity;
}

template <std::size_t N>
int findCelebrity (bool (&F)[N][N])
{
    int i = 0, j = 1;
    while (j < N){
        if(F[i][j]) {
            i=j++;
        } else {
            ++j;
        }

    }
    return i;
}


#define N 10

using namespace std;
int main (void)
{
    bool A[N][N] = {false};
    default_random_engine g;
    uniform_int_distribution<int> d(0,1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            if(j==i) {
                A[i][j]=true;
            }
            if(d(g) == 1) {
                A[i][j] = true;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        A[i][7] = true;
        A[7][i] = false;
        A[i][i] = true;
    }
    
    std::cout << A << std::endl;
    cout << "The celebrity is " << findCelebrity(A) << endl;
    cout << "The celebrity is " << findCelebritySlow(A) << endl;
    return 0;
}
