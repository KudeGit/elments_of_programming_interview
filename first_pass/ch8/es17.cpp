#include <iostream>
#include "list.hpp"
#include "../utils.hpp"

template <class T>
void print_list (std::shared_ptr<T> x)
{
    while (x) {
        std::cout << *x << ", ";
        x = x->next;
    }
    std::cout << std::endl;
}

template <class T>
void concatenate_lists (std::shared_ptr<T>& head,
        std::shared_ptr<T>& low_head,
        std::shared_ptr<T>& low,
        std::shared_ptr<T>& equal_head,
        std::shared_ptr<T>& equal,
        std::shared_ptr<T>& high_head,
        std::shared_ptr<T>& high)
{
    if(low_head) {
        head = low_head;
        if(equal_head) {
            low->next = equal_head;
            low = equal;
        }
        if(high_head) {
            low->next = high_head;
            low = high;
        }
        low->next = nullptr;
    } else if (equal_head) {
        head = equal_head;
        if(high_head) {
            equal->next = equal_head;
            equal = high;
        }
        equal->next = nullptr;
    } else if(high_head) {
        head = high_head;
        high->next = nullptr;
    } else {
        return;
    }

}


template <class T>
void append_to_list (std::shared_ptr<T>& x_head,
        std::shared_ptr<T>& x,
        std::shared_ptr<T>& curr,
        std::shared_ptr<T>& prev)
{
    if(!x_head) {
        x_head = curr;
        x = x_head;
        prev = nullptr;
        curr = curr->next;
        x->next = nullptr;
        return;
    }
    x->next = curr;
    if(prev) {
        prev->next = curr->next;
    }
    curr = curr->next;
    x = x->next;
    x->next = nullptr;
}

template <class T>
void pivoting (List<T>& l, T k)
{
    auto prev = l.head;
    auto curr = l.head;
    auto low = l.head;
    auto low_head = l.head;
    auto high = l.head;
    auto high_head = l.head;
    auto equal = l.head;
    auto equal_head = l.head;

    high_head = nullptr;
    high = nullptr;
    low_head = nullptr;
    low = nullptr;
    equal_head = nullptr;
    equal = nullptr;

    prev = nullptr;
    while (curr) {
        if (curr->data > k) {
            append_to_list(high_head, high, curr, prev);
        } else if (curr->data == k) {
            append_to_list(equal_head, equal, curr, prev);
        } else {
            append_to_list(low_head, low, curr, prev);
        }
    }
    concatenate_lists(l.head, low_head, low, equal_head, equal, high_head, high);

    return;
}


int main (void)
{
    auto l = create_and_populate_list_random(0, 10, 15);
    std::cout << l << std::endl;
    pivoting(l, 5);
    std::cout << l << std::endl;
    return 0;
}
