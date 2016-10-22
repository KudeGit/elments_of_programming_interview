#include <iostream>
#include "list.hpp"

template <class T>
List<T>& reverse (List<T>& l)
{
    std::shared_ptr<ListNode<T>> prev = nullptr;
    std::shared_ptr<ListNode<T>> curr = l.head;
    std::shared_ptr<ListNode<T>> next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l.head = prev;
    return l;
}

int main (void)
{
    List<int> l;
    for (int i = 0; i < 10; ++i) {
        l.insert_front(i);
    }
    std::cout << l << std::endl;
    l = reverse(l);
    std::cout << l << std::endl;
    return 0;
}
