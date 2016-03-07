#include <iostream>
#include <stack>
#include <stdexcept>

template <class T>
struct max_stack {
    std::stack<T> s;
    std::stack<T> max_so_far;

    void push (T t);
    T pop(void);
    const T&  max (void) const;
    const bool empty(void) const {return s.empty();}
};


template <class T>
void max_stack<T>::push (T t)
{
    s.push(t);
    if (max_so_far.empty()) {
        max_so_far.push(s.top());
    } else {
        if (s.top() > max_so_far.top()) {
            max_so_far.push(s.top());
        }
    }
}

template <class T>
T max_stack<T>::pop(void)
{
    if(s.empty()) {
        throw std::length_error("stack is empty");
    }
    auto top = s.top();
    s.pop();
    if(top >= max_so_far.top()) {
        max_so_far.pop();
    }
    return top;
}

template <class T>
const T& max_stack<T>::max (void) const
{
    if(max_so_far.empty()) {
        throw std::length_error("stack is empty");
    }
    return max_so_far.top();
}

int main (void) 
{
    max_stack<int> s;
    for(int i = 10; i >= 0; --i) {
        s.push(i);
    }
    while(!s.empty()) {
        std::cout << "max" << s.max() << std::endl;
        auto x = s.pop();
        std::cout << "popped el: " << x << std::endl;
    }
    return 0;
}
