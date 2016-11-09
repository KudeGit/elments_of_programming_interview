//from leetcode 
//
#include <iostream>
#include <queue>
#include "ch11.hpp"



template <class OP1, class OP2>
inline void MedianFinder::push_and_rebalance (std::priority_queue<int, std::vector<int>, OP1>& A,
        std::priority_queue<int, std::vector<int>, OP2>& B,
        const int num, const int threshold)
{
    A.push(num);
    if (A.size() - B.size() > threshold) {
        B.push(A.top());
        A.pop();
    }
}


// Adds a number into the data structure.
void MedianFinder::addNum(int num)
{
    if (maxH.empty()) {
        maxH.push(num);
    } else {
        if (num <= maxH.top()) {
            push_and_rebalance(maxH, minH, num, 1);
        } else {
            push_and_rebalance(minH, maxH, num, 0);
        }
    }
}

// Returns the median of current data stream
double MedianFinder::findMedian()
{
    if (minH.empty()) {
        return maxH.empty() ? 0 : maxH.top();
    }
    return ((maxH.size() + minH.size()) & 0x01lu) ? maxH.top() : static_cast<double>(minH.top()+maxH.top()) / 2.0;
}
