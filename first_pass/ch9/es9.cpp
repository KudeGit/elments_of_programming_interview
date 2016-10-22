#include <iostream>
#include <stack>
#include "../utils.hpp"

template <class T>
void sort (std::stack<T>& S)
{
    std::stack<T> helper;
    while (!S.empty()) {
        while (helper.empty() || (!S.empty() && helper.top() >= S.top())) {
            helper.push(S.top()); S.pop();
        }
        if (!S.empty()) {
            auto tmp = S.top(); S.pop();
            while(!helper.empty() && helper.top() < tmp) {
                S.push(helper.top()); helper.pop();
            }
            helper.push(tmp);
        }
    }
    while(!helper.empty()) {
        S.push(helper.top()); helper.pop();
    }
}

int main (void)
{
    std::stack<int> S;
    S.push(7);
    S.push(3);
    S.push(2);
    S.push(0);
    S.push(1);
    S.push(5);
    sort(S);
    while(!S.empty()) {
        std::cout << S.top() << ", ";
        S.pop();
    }
    std::cout << std::endl;
}
