#include <iostream>
#include "list.hpp"
#include "../utils.hpp"


template <class T>
void update_pointers (T& a, T& x, T& y)
{
    T tmp = a->next;
    if(x == nullptr) {
        x = a;
        x->next = nullptr;
        a = tmp;
        y = x;
    } else {
        y->next = a;
        y = y->next;
        y->next = nullptr;
        a = tmp;
    }

}

template<class T>
List<T> merge(List<T>& l1, List<T>& l2)
{
    auto& l1_ptr = l1.head;
    auto& l2_ptr = l2.head;
    List<T> res;
    std::shared_ptr<ListNode<T>> x = nullptr, y = nullptr;
    while (l1_ptr != nullptr && l2_ptr != nullptr) {
        if (*l1_ptr <= *l2_ptr) {
            update_pointers(l1_ptr, x, y);
        } else {
            update_pointers(l2_ptr, x, y);
        }
    }
    debug("");
    while (l1_ptr) {
        update_pointers(l1_ptr, x, y);
    }
    while (l2_ptr) {
        update_pointers(l2_ptr, x, y);
    }
    l1.head = nullptr;
    l2.head = nullptr;
    res.head = x;
    return res;
}

template<class T>
void reverse (List<T>& l)
{
    if (!l.head) {
        return;
    }
    auto curr = l.head;
    std::shared_ptr<ListNode<T>> prev = nullptr;
    std::shared_ptr<ListNode<T>> next = nullptr;
    while(curr) {
        next = curr->next;
        curr->next = prev; 
        prev = curr;
        curr = next;
    }
    l.head = prev;
}

int main (void)
{
    List<int> l1, l2;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    for (int i = 9; i < 30; ++i) {
        l2.push_back(i);
    }
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
    auto l3 = merge(l2, l1);
    std::cout << l3 << std::endl;
    reverse(l3);
    std::cout << l3 << std::endl;
    
    return 0;
}
