#include <iostream>
#include <stack>
#include "../utils.hpp"


template <class T>
class Queue {
    private:
        std::stack<T> s1;
        std::stack<T> s2;
        void swap(Queue<T>& other) {
            std::swap(s1, other.s1);
            std::swap(s2, other.s2);
        }
    public:
        Queue () {};
        Queue (const Queue<T>& other) : s1(other.s1), s2(other.s2) {};
        Queue (Queue<T>&& other) : s1(std::move(other.s1)),
            s2(std::move(other.s2)) {};
        Queue& operator= (Queue<T> other) {
            swap(other);
            return *this;
        }
        ~Queue() {}

        void enqueue (const T t);
        T dequeue (void);
        bool empty (void) {
            return s1.empty() && s2.empty();
        }
};


template <class T>
void Queue<T>::enqueue (const T t)
{
    s1.push(t);
    return;
}
template <class T>
T Queue<T>::dequeue (void)
{
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    auto res = s2.top();
    s2.pop();
    return res;
}


int main (void)
{
    Queue<int> q;
    for (int i = 0; i < 10; ++i) {
        q.enqueue(i);
    }
    
    while (!q.empty()) {
        std::cout << q.dequeue() << std::endl;
    }
    return 0;
}
