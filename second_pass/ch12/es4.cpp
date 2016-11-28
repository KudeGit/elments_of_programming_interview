#include <iostream>
#include <vector>
#include "../../utils.hpp"

using std::vector;

//tested in leetcode:  https://leetcode.com/problems/search-in-rotated-sorted-array/
int search(vector<int>& A, int target)
{
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        auto m = l + ((r-l) >>1);
        if (A[m] == target) {
            return m;
        }
        if (A[l] <= A[m] && A[m] <= A[r]) {
            //simple binary search
            if (target < A[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (A[l] <= A[m] && A[m] >= A[r]) {
                if (target >= A[l] && target < A[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (A[l] >= A[m] && A[m] <= A[r]) {
                if (target >= A[m] && target <= A[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
    }
    return -1;
}

//looking for the smallest
int find_smallest (const vector<int>& A) 
{
    if (A.empty()) {
        return -1;
    }
    int l = 0, r = A.size() - 1;
    while (l < r) {
        auto m = l + ((r - l) >> 1);
        if (A[m] > A[r]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}
