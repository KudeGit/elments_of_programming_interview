#include <iostream>
#include <queue>
#include <algorithm>
#include "../utils.hpp"

template <class T>
struct Median {
    std::priority_queue<T,std::vector<T>, std::greater<T>> minH;
    std::priority_queue<T,std::vector<T>, std::less<T>> maxH;
    void push (const T& t);
    T getMedian();
};



template <class T>
void Median<T>::push(const T& t)
{
    if (maxH.empty()) {
        maxH.push(t);
        return;
    } else {
        if(t > maxH.top()) {
            minH.push(t);
            if (minH.size() > maxH.size()) {
                maxH.push(minH.top());
                minH.pop();
            }
        } else {
            maxH.push(t);
            if (maxH.size() > minH.size() + 1) {
                minH.push(maxH.top());
                maxH.pop();
            }
        }
    }
}


template <class T>
T Median<T>::getMedian ()
{
    if (maxH.empty()) {
        debug("fuck");
        throw std::logic_error("median of an empty stream");
    }
    return maxH.top();
}



int main (void)
{
    std::vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::reverse(A.begin(), A.end());
    std::cout << A << std::endl;
    Median<int> M;
    for (const auto& a: A) {
        debug(a);
        M.push(a);
        debug(M.getMedian());
    }
    return 0;

}
