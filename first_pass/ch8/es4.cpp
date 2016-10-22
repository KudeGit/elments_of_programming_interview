#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
List<T>& reverse_k (List<T>& l, const int k)
{
    if (k < 2) {
        return l;
    }
    std::shared_ptr<ListNode<T>> curr = l.head;
    std::shared_ptr<ListNode<T>> prev = nullptr;
    std::shared_ptr<ListNode<T>> next;
    std::shared_ptr<ListNode<T>> prev_sublist_last = prev;
    std::shared_ptr<ListNode<T>> curr_sublist_last = curr;
    int i = k;

    while (curr) {
        i = k;
        while (i && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            --i;
        }
        if(i == 0) {
            if(prev_sublist_last) {
                prev_sublist_last->next = prev;
            } else {
                l.head = prev;
            }
            if(curr_sublist_last) {
                curr_sublist_last->next = curr;
            }
            prev_sublist_last = curr_sublist_last; 
            curr_sublist_last = curr;
        } else {
            break;
        }
    }
    if(i) {
        curr = prev;
        prev = nullptr;
        i = k - i;
        while (curr && i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            --i;
        }
        prev_sublist_last->next = prev;
    }
    return l;
}



int main (void)
{

    auto l =  create_and_populate_list<int>(0, 15);
    std::cout << l << std::endl;
    l = reverse_k(l, 2);
    std::cout << l << std::endl;
    return 0;
}


