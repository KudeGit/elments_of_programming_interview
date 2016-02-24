#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
void r_shift (List<T> &l, int k)
{
    if(k <= 0) {
        return;
    }
    auto curr = l.head, prev = l.head;
    prev = nullptr;
    while (curr && k) {
        prev = curr->next ? curr : nullptr;
        curr = curr->next ? curr->next : l.head;
        --k;
    }
    if (!prev) {
        return;
    }
    prev->next = nullptr;
    auto old_head = l.head;
    l.head = curr;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = old_head;
}


int main (void)
{
    auto l = create_and_populate_list<int>(0,10);
    std::cout << l << std::endl;
    r_shift(l, 9);
    std::cout << l << std::endl;
}
