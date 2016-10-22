#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
List<T>& reverse_sub_list (List<T>& l, const int s, const int f)
{
    if (f <= s) {
        return l;
    }
    int i = 1;
    auto curr = l.head;
    std::shared_ptr<ListNode<T>> prev = nullptr;
    std::shared_ptr<ListNode<T>> next;
    while(curr && i < s) {
        prev = curr;
        curr = curr->next;
        ++i;
    }
    auto last_first_part = prev;
    auto last_sub_list = curr;
    while (curr && i < f) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        ++i;
    }
    if(last_first_part) {
        last_first_part->next = prev;
    } else {
        l.head = prev;
    }
    if(last_sub_list) {
        last_sub_list->next = curr;
    }

    return l;
}


int main (void)
{
    auto l = create_and_populate_list<int>(1,10);
    std::cout << l << std::endl;
    l = reverse_sub_list(l, 3, 11);
    std::cout << l << std::endl;
    return 0;
}
