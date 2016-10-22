#include <iostream>
#include "list.hpp"

template<class T>
ListNode<T> overlapping_list_with_cycle (const List<T>& l1, const List<T>& l2)
{
    auto x = find_loop(l1);
    auto y = find_loop(l2);
    if(!(x && y)) {
        return;
    }
    auto tmp = y;
    do {
        tmp = tmp->next;
    } while (tmp != y || y != x)
    return y == x ? y : nullptr;
}

