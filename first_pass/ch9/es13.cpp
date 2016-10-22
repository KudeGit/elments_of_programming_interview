#include <iostream>
#include <queue>
#include <random>
#include "../utils.hpp"





template <class T>
class Queue {
    private:
        std::queue<T> Q;
        std::deque<T> maxQ;
    public:
        void push(const T& t);
        T pop();
        T max();
        bool empty();
        T front();
};

template <class T>
T Queue<T>::front()
{
    if (Q.empty()) {
        std::logic_error("Q is empty");
    }
    return Q.front();
}

template <class T>
bool Queue<T>::empty()
{
    return Q.empty();
}

template <class T>
void Queue<T>::push (const T& t)
{
    Q.push(t);
    while(!maxQ.empty() &&  maxQ.back() < t) {
        maxQ.pop_back();
    }
    maxQ.emplace_back(t);
    auto it = maxQ.begin();
    for (;it != maxQ.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

}

template <class T>
T Queue<T>::pop()
{
    if(Q.empty()) {
        throw std::logic_error("Q is empty");
    }
    auto ret_val = Q.front();
    Q.pop();
    if(maxQ.front() == ret_val) {
        maxQ.pop_front();
    }
    return ret_val;
}


template <class T>
T Queue<T>::max()
{
    if(maxQ.empty()) {
        throw std::logic_error("max queue is empty");
    }
    return maxQ.front();
}

int main (void)
{
    Queue<int> qm; 
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<int> d(0,10);
    int max = -1;
    for (int i = 0; i < 10; ++i) {
        auto n = d(g);
        max = std::max(max, n);
        qm.push(n);
        std::cout << n << " / " << max << " / " << qm.max() << std::endl;
    }
    banner ("########");
    while(!qm.empty()) {
        std::cout << qm.front()  << " / " << qm.max() << std::endl;
        auto curr = qm.pop();
    }
    

    return 0;
}
