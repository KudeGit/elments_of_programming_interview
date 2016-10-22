#include <iostream>
#include <vector>
#include "utils.hpp"


using namespace std;

int coverPoints(vector<int> &X, vector<int> &Y) {
    int steps  = 0;
    for (size_t i = 1; i < X.size(); ++i) {
        int x = std::min(abs(X[i] - X[i-1]), abs(Y[i]-Y[i-1]));
        debug(x);
        int y = 0;
        if (abs(X[i] - X[i-1]) > abs(Y[i] - Y[i-1])) {
            y = abs(X[i] - X[i-1]) - x;
        } else {
            y = abs(Y[i] - Y[i-1]) - x;
        }
        steps += y + x;
    }
    return steps;
}


int main (void)
{
    //std::vector<int> A = { -5, 7, -12, 4, -6, 2, -5, -12, -6, 3, 11, 10, -8, 11, -13, -8, 5, -12, 4, 4};
    //std::vector<int> B = {-6, 6, -8, -13, -2, -9, -10, -10, -7, -14, 9, -8, -4, 8, 13, -11, 13, 5, 9, 11};
    vector<int> A = {4, 8, -7, -5, -13, 9, -7, 8};
    vector<int> B = {4, -15, -10, -3, -13, 12, 8, -8};
    auto s = coverPoints(A,B);
    cout << s << endl;
    return 0;
}
