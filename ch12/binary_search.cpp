#include <iostream>
#include <cassert>
#include <vector>


template <class T>
int search (const std::vector<T>& A, T target)
{
    int l = 0;
    int r = A.size() - 1;
    while (l <= r) {
        int m = (r - l) >> 1;
        if(A[m] == target) {
            return m;
        } else {
            if (A[m] > target) { // search left half
                r = m - 1;
            } else { //serch right half
                l = m + 1;
            }
        }
    }
    return -1;
}


int main (void)
{
    std::vector<int> A1 = {};
    std::vector<int> A2 = {1};
    std::vector<int> A3 = {1, 10};
    std::vector<int> A4 = {1,7,10};
    std::vector<int> A5 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> A6 = {1,2,3,4,5,6,7,8,9,10,11};

    int k = search(A1, 10);
    
    k = search(A2, 10);
    assert(k == -1);
    k = search(A2, 1);
    assert(k==0);
    return 0;

    k = search(A3, 11);
    assert(k == -1);
    k = search(A3, 0);
    assert(k == -1);

    k = search(A3, 1);
    assert(k == 0);
    k = search(A3, 10);
    assert(k == 1);



    k = search(A4, 0);
    assert(k == -1);
    k = search(A4, 11);
    assert(k == -1);
    k = search(A4, 1);
    assert(k == 0);
    k = search(A4, 7);
    assert(k == 1);
    k = search(A4, 10);
    assert(k == 2);
    k = search(A4, 5);
    assert(k == -1);
    k = search(A4, 9);
    assert(k == -1);

    
    return 0;

}
