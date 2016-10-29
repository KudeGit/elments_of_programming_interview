#ifndef __CH_9__
#define __CH_9__

#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
int evalute_rpn (const std::string& str);

std::string transform_to_rpn (const std::vector<std::string>& strs);

//can improve storing a pair in s_max, element,  number of times
template <class T>
struct max_stack {
    std::stack<T> s;
    std::stack<T> s_max;
    void push(const T t) {
        s.push(t);
        if (s_max.empty() || s.top() >= s_max.top()) {
            s_max.push(t);
        }
    }
    T& top() {
        if (s.empty()) {
            throw std::logic_error("Peeking empty stack");
        }
        return s.top();
    }
    T& max() {
        if (s_max.empty()) {
            throw std::logic_error("Peeking Empty max stack");
        }
        return s_max.top();
    }
    void pop() {
        if (s.empty()) {
            throw std::logic_error("Popping empty stack");
        }
        if (s_max.empty()) {
            throw std::logic_error("Empty max stack");
        }
        if (s.top() == s_max.top()) {
            s_max.pop();
        }
        s.pop();
    }
    bool empty() {
        if (s_max.empty() != s.empty()) {
            throw std::logic_error("Only one stack is empty");
        } else {
            return s_max.empty() && s.empty();
        }
    }
};

#endif //__CH_9__
