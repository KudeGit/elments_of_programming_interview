#include <iostream>
#include <vector>
#include "../utils.hpp"


template <class T>
class Queue {
    private:
        std::vector<T> A;
        size_t n = 0;
        size_t first = 0;
        size_t last = 0;
        void swap (Queue<T>& other) {
            std::swap(A, other.A);
            std::swap(first, other.first);
            std::swap(last, other.last);
            std::swap(n, other.n);
        }
    public:
        Queue() : n(0), first(0), last(0) {};
        Queue(const size_t n) : A(std::vector<T>(n)), n(0),
            first(0), last(0) {}
        Queue(const Queue<T>& other) :A(other.A), n(other.n),
            first(A.first), last(A.last) {}
        Queue(Queue<T>&& other): A(std::move(other.A)), n(other.n),
            last(other.last), first(other.first) {}
        ~Queue() {};
        Queue& operator= (Queue<T> other) {
            swap(other);
            return *this;
        }
        size_t size (void) {
            return n;
        }
        void enqueue (const T t) {
            if(last == A.size() ) {
                error("resizing undeling array");
                A.resize(A.size() * 2);
            }
            A[last++] = t;
            ++n;
            return;
        }
        T dequeue (void) {
            if(first < last) {
                auto res = A[first++];
                --n;
                return res;
            } else {
                throw std::logic_error("dequeueing from and empty queue");
            }
        }
        T head (void) {
            return A[first];
        }
};



int main (void)
{
    Queue<int> q(5);
    std::cout << q.size() << std::endl;
    for (int i = 0; i < 10; ++i) {
        q.enqueue(i);
        std::cout << q.size() << std::endl;
    }
    while (q.size()) {
        auto a = q.dequeue();
        std::cout << a << std::endl;
    }
    return 0;
}
