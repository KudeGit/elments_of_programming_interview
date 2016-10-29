#ifndef __CH_8__
#define __CH_8__

#include <iostream>
#include <memory>
#include "list.hpp"

template <class T>
List<T> merge_sorted_list (List<T> &A, List<T>& B)
{
    if (!A.head) {
        return B;
    }
    if (!B.head) {
        return A;
    }

    List<T> l;
    std::shared_ptr<ListNode<T>> prev = nullptr;
    auto& xA = A.head;
    auto& xB = B.head;
    while (xA && xB) {
        if (!l.head) {
            l.head = xA->data < xB->data ? xA : xB;
            if (l.head == xA) {
                xA = xA->next;
            } else {
                xB = xB->next;
            }
            prev = l.head;
        } else {
            auto& next = xA->data < xB->data ? xA : xB;
            prev->next = next;
            prev = prev->next;
            next = next->next;
        }
    }

    auto& x = xA == nullptr ? xB : xA;
    while(x) {
        prev->next = x;
        x = x->next;
        prev = prev->next;
    }
    A.head = nullptr;
    B.head = nullptr;
    return l;
}

template <class T>
void reverse (List<T>& l)
{
    std::shared_ptr<ListNode<T>> prev = nullptr;
    std::shared_ptr<ListNode<T>> next = nullptr;
    auto curr = l.head;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l.head = prev;
    return;
}

#endif //__CH_8__
