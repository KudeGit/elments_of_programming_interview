#include <iostream>
#include "list.hpp"
#include "../utils.hpp"




template <class T>
void update_list (const std::shared_ptr<ListNode<T>>& curr, 
    std::shared_ptr<ListNode<T>>& x, std::shared_ptr<ListNode<T>>& head)
{
    if(x) {
        x->next = curr;
        x = x->next;
    } else {
        x =  curr;
        head = curr;
    }
}

//use the position in the list as index
template <class T>
void odd_even (List<T> &l)
{
    std::shared_ptr<ListNode<T>> x_even = nullptr;
    std::shared_ptr<ListNode<T>> head_even = nullptr;
    std::shared_ptr<ListNode<T>> y_odd = nullptr;
    std::shared_ptr<ListNode<T>> head_odd = nullptr;

    auto curr = l.head;
    if(curr == nullptr) {
        return;
    }
    int pos = 0;
    while (curr) {
        if((pos & 0x01) == 0) {
            update_list(curr, x_even, head_even);
        } else {
            update_list(curr, y_odd, head_odd);
        }
        curr = curr->next;
        ++pos;
    }
    x_even->next = head_odd;
    y_odd->next = nullptr;
    l.head = head_even;
}


int main (void)
{
    auto l = create_and_populate_list<int>(0, 10);
    std::cout << l << std::endl;
    odd_even(l);
    std::cout << l << std::endl;
    return 0;
}
