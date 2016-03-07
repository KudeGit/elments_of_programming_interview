#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
void create_loop (std::shared_ptr<ListNode<T>> x)
{
    if (!x) {
        return;
    }
    auto y = x;
    while(y->next) {
        y = y->next;
    }
    y->next = x;
}
template <class T> 
void advance_head (List<T>& l, int k)
{
    auto x = l.head;
    while (x && k) {
        x = x->next;
            --k;
    }
    l.head = x;
}

template <class T>
std::shared_ptr<ListNode<T>> find_median_in_circular_list (const List<T>& l)
{
    auto curr = l.head;
    auto prev = l.head;
    do {
        prev = curr;
        curr = curr ? curr->next : curr;
    } while (curr && curr != l.head && prev < curr);
    auto first = curr;
    prev = curr;
    auto fast = curr;
    do {
        fast = fast ? fast->next : fast;
        if(fast == first){
            prev = curr;
            curr = curr->next;
            break;
        }
        if(fast) {
            prev = curr;
            curr = curr->next;
            fast = fast->next;
        }
    } while (fast != first);
    return prev;
}


int main (void)
{
    List<int> l = create_and_populate_list<int>(0,10);
    create_loop(l.head);
    advance_head(l, 2);
    auto median = find_median_in_circular_list(l);
    
    std::cout << *median << std::endl;
    return 0;
}
