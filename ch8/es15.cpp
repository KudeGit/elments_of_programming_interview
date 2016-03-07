#include <iostream>
#include "list.hpp"
#include "../utils.hpp"


template <class T>
void reverse (std::shared_ptr<ListNode<T>>& head)
{
    auto curr = head;
    auto next = head;
    auto prev = head;
    prev = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <class T>
bool is_palindrome (List<T>& l)
{
    auto slow = l.head;
    auto fast = l.head;
    auto prev = l.head;
    prev = nullptr;
    while (fast) {
        fast = fast->next;
        if(fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
    }
    prev->next = nullptr;
    reverse(slow);
    fast = l.head;
    while (fast && slow) {
        if (fast->data != slow->data) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}


int main (void)
{
    List<int> l;
    for (int i = 0; i < 11; ++i) {
        l.push_back(i);
    }
    for (int i = 9; i >= 0; --i) {
        l.push_back(i);
    }
    std::cout << l << std::endl;
    std::cout << is_palindrome(l) << std::endl;
}

