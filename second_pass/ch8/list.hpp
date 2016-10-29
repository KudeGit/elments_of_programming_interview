#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>
#include <memory>


template <class T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;
    ListNode<T>(const T& d) : data(d), next(nullptr) {}
    ListNode<T>():data(T()), next(nullptr) {}
};
template <class T>
std::ostream& operator<< (std::ostream& out, const ListNode<T>& ln)
{
    out << ln.data;
    return out;
}

//template <class T>
//using list_ptr = std::shared_ptr<ListNode<T>>;



template <class T>
struct List {
    std::shared_ptr<ListNode<T>> head = nullptr;
    std::shared_ptr<ListNode<T>> tail = nullptr;
    void push_front(const T& data);
};



template <class T>
void List<T>::push_front(const T& data)
{
    if(!head) {
        head = std::make_shared<ListNode<T>>(data);
    } else {
        auto x = head;
        head = std::make_shared<ListNode<T>>(data);
        head->next = x;
    }
}


#endif //__LIST_HPP__
