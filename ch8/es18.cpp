#include <iostream>
#include <tuple>
#include "list.hpp"
#include "../utils.hpp"




template <class T> 
std::shared_ptr<T> find_min(std::shared_ptr<T>& curr_head)
{
    auto curr = curr_head;
    auto prev = curr_head;
    auto curr_min = curr;
    auto prev_min = curr;
    prev = nullptr;
    prev_min = nullptr;

    while (curr) {
        if (*curr < *curr_min) {
            prev_min = prev;
            curr_min = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    if(!prev_min) {
        //first element
        curr_head = curr_head->next;
    } else {
        //any other element
        prev_min->next = curr_min->next;
    }
    curr_min->next = nullptr;
    return curr_min;
}
template <class T>
void insert_min(std::shared_ptr<T>& sorted_head, std::shared_ptr<T>& sorted_tail, std::shared_ptr<T>& curr_min)
{
    if(!sorted_head) {
        sorted_head = curr_min;
        sorted_tail = sorted_head;
        sorted_tail->next = nullptr;
        return;
    }
    sorted_tail->next = curr_min;
    sorted_tail = sorted_tail->next;
    sorted_tail->next = nullptr;
}

template <class T>
void insertion_sort (List<T>& l)
{
    auto sorted_head = l.head;
    auto sorted_tail = l.head;
    auto curr_head = l.head;
    auto curr_min = l.head;

    sorted_head = nullptr;
    sorted_tail = nullptr;

    while (curr_head) {
        curr_min = find_min(curr_head);
        insert_min (sorted_head, sorted_tail, curr_min);
    }
    l.head = sorted_head;
}


template <class T>
std::shared_ptr<T>  split (std::shared_ptr<T>& start)
{
    if(!start) {
        return nullptr;
    }
    auto slow = start;
    auto fast = start;
    auto prev_slow = start;
    prev_slow = nullptr;
    while (fast) {
        fast = fast->next;
        if (fast) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next;
        }
    }
    if(!prev_slow) {
        return nullptr;
    }
    prev_slow->next = nullptr;
    auto new_head = slow;

    return new_head;
}

template <class T>
void insert_node(std::shared_ptr<T>& head,
        std::shared_ptr<T>& tail,
        std::shared_ptr<T> curr)
{
    if(!head) {
        head = curr;
        tail = curr;
    } else {
        tail->next = curr;
        tail = tail->next;
    }
    tail->next = nullptr;
}

template<class T>
std::shared_ptr<T> remove_and_update (std::shared_ptr<T>& x)
{
    auto y = x;
    x = x->next;
    return y;
}

template <class T>
std::shared_ptr<T> merge_sort (std::shared_ptr<T> head)
{
    if(!head->next) {
        return head;
    }
    auto right_head  = split(head);
    auto left_head = head;


    left_head = merge_sort(left_head);
    right_head = merge_sort(right_head);
    auto l = left_head;
    auto r = right_head;
    std::shared_ptr<T> new_head = nullptr;
    std::shared_ptr<T> new_tail = nullptr;
    //miss to remove from list;
    while (l && r) {
        std::shared_ptr<T> x = nullptr;
        if (l->data <= r->data) {
            x = remove_and_update(l);
        } else {
            x = remove_and_update(r);
        }
        insert_node(new_head, new_tail, x);
    }
    while(l) {
        auto x = remove_and_update(l);
        insert_node(new_head, new_tail, x);
    }
    while(r) {
        auto x = remove_and_update(r);
        insert_node(new_head, new_tail, x);
    }
    return new_head;
}

template <class T>
void merge_sort (List<T>& l)
{
    l.head = merge_sort(l.head);
}



int main (void)
{
    auto l = create_and_populate_list_random(0, 10, 10);
    std::cout << l << std::endl;
    //insertion_sort(l);
    //std::cout << l << std::endl;
    merge_sort(l);
    std::cout << l << std::endl;
    return 0;
}
